#include "AC_CustomControl_Tracker.h"

#if CUSTOMCONTROL_Tracker_ENABLED

#include <GCS_MAVLink/GCS.h>

// table of user settable parameters
const AP_Param::GroupInfo AC_CustomControl_Tracker::var_info[] = {
    // @Param: PARAM1
    // @DisplayName: Pitch param1
    // @Description: Dummy parameter for Pitch custom controller backend
    // @User: Advanced
    AP_GROUPINFO("PARAM1", 1, AC_CustomControl_Tracker, param1, 0.0f),

    // @Param: PARAM2
    // @DisplayName: Pitch param2
    // @Description: Dummy parameter for Pitch custom controller backend
    // @User: Advanced
    AP_GROUPINFO("PARAM2", 2, AC_CustomControl_Tracker, param2, 0.0f),

    // @Param: PARAM3
    // @DisplayName: Pitch param3
    // @Description: Dummy parameter for Pitch custom controller backend
    // @User: Advanced
    AP_GROUPINFO("PARAM3", 3, AC_CustomControl_Tracker, param3, 0.0f),

    AP_GROUPEND
};

// initialize in the constructor
AC_CustomControl_Tracker::AC_CustomControl_Tracker(AC_CustomControl& frontend, AP_AHRS_View*& ahrs, AC_AttitudeControl*& att_control, AP_MotorsMulticopter*& motors, float dt) :
    AC_CustomControl_Backend(frontend, ahrs, att_control, motors, dt)
{
    AP_Param::setup_object_defaults(this, var_info);

    acc_controller.initialize();

}

// update controller
// return roll, pitch, yaw controller output
Vector3f AC_CustomControl_Tracker::update(void)
{
    // reset controller based on spool state
    switch (_motors->get_spool_state()) {
        case AP_Motors::SpoolState::SHUT_DOWN:
        case AP_Motors::SpoolState::GROUND_IDLE:
            // We are still at the ground. Reset custom controller to avoid
            // build up, ex: integrator
            reset();
            break;

        case AP_Motors::SpoolState::THROTTLE_UNLIMITED:
        case AP_Motors::SpoolState::SPOOLING_UP:
        case AP_Motors::SpoolState::SPOOLING_DOWN:
            // we are off the ground
            break;
    }

    Vector3f gyro_latest = _ahrs->get_gyro_latest();
    float speed_magnitude = _ahrs->groundspeed();
    Vector3f accel_body = _ahrs->get_accel_ef();

    // '<Root>/az_cmd'
    float arg_az_cmd{ 0.1F };

    // '<Root>/acc_xyz_body'
    float arg_acc_xyz_body[3]{ accel_body.x, accel_body.y, accel_body.z };

    // '<Root>/pitch_rate'
    float arg_pitch_rate{ gyro_latest.y };

    // '<Root>/speed_magnitude'
    float arg_speed_magnitude{ speed_magnitude };

    // '<Root>/alpha'
    float arg_alpha{ 0.0F };

    // '<Root>/beta'
    float arg_beta{ 0.0F };

    // '<Root>/ay_cmd'
    float arg_ay_cmd{ 0.0F };

    // '<Root>/yaw_rate'
    float arg_yaw_rate{ gyro_latest.z };

    // '<Root>/roll_cmd'
    float arg_roll_cmd{ 0.0F };

    // '<Root>/control_cmd'
    float arg_control_cmd[3];

    acc_controller.step(arg_az_cmd, arg_acc_xyz_body, arg_pitch_rate,
    arg_speed_magnitude, arg_alpha, arg_beta, arg_ay_cmd, arg_yaw_rate,
    arg_roll_cmd, arg_control_cmd);
    
    return Vector3f(arg_control_cmd[0], arg_control_cmd[1], arg_control_cmd[2]);
}

// reset controller to avoid build up on the ground
// or to provide bumpless transfer from arducopter main controller
void AC_CustomControl_Tracker::reset(void)
{
}

#endif
