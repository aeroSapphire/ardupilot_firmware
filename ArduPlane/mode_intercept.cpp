#include "mode.h"
#include "Plane.h"
#include <AP_InertialSensor/AP_InertialSensor.h>
#include <AC_Simulink/inter_acc_controller.h>

void ModeIntercept::update()
{   
    inter_acc_controller controller;

}

void ModeIntercept::run()
{
    inter_acc_controller controller;
    controller.initialize();
    Vector3f gyro_latest = ahrs.get_gyro_latest();
    Vector3f acc_latest = ahrs.get_accel();
    // Gather necessary inputs for the controller
    real32_T az_cmd = {0.1}; // Commanded vertical acceleration
    real32_T acc_xyz_body[3] = {acc_latest.x, acc_latest.y, acc_latest.z};
    real32_T pitch_rate = gyro_latest.y;
    real32_T speed_magnitude = {0.0}; //ahrs.get_velocity_NED();
    real32_T alpha = {0.0};
    real32_T beta = {0.0};
    real32_T ay_cmd = {0.0};
    real32_T yaw_rate = gyro_latest.z;
    real32_T roll_cmd = {0.0};
    real32_T control_cmd[3]; // Output commands: roll, pitch, yaw

    // Call the custom controller
    controller.step(az_cmd, acc_xyz_body, pitch_rate, speed_magnitude, alpha,
                    beta, ay_cmd, yaw_rate, roll_cmd, control_cmd);

    // Extract the control commands
    //float roll_output = control_cmd[0];
    //float pitch_output = control_cmd[1];
    //float yaw_output = control_cmd[2];

    // Send commands to the motor mixer
    //AP_Motors::set_roll(roll_output);
    //AP_Motors::set_pitch(pitch_output);
    //AP_Motors::set_yaw(yaw_output);
}
