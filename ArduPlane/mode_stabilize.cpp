#include "mode.h"
#include "Plane.h"
#include <AP_InertialSensor/AP_InertialSensor.h>
#include <AC_Simulink/inter_acc_controller.h>
#include <AC_Guidance/guidance_law.h>
#include "GCS_MAVLink/GCS.h" // Include the GCS communication header


void ModeStabilize::update()
{   


}

void ModeStabilize::run()
{
    guidance.initialize();
    controller.initialize();

    Vector3f missile_position;  // Declare the Vector3f variable
    if (ahrs.get_relative_position_NED_origin(missile_position)) {
        // Successfully retrieved the position
        // Use missile_position here
    } else {
        // Handle failure case
        printf("Failed to get missile position relative to NED origin.\n");
    }

    // '<Root>/POS_M'
    float arg_POS_M[3]{ missile_position.x, missile_position.y, -missile_position.z };

    // '<Root>/POS_T'
    float arg_POS_T[3]{ 5000.0F, 0.0F, 6000.0F };

    // '<Root>/Az_cmd'
    double arg_Az_cmd;

    // '<Root>/Ay_cmd'
    double arg_Ay_cmd;

    guidance.step(arg_POS_M, arg_POS_T, &arg_Az_cmd, &arg_Ay_cmd);


    Vector3f gyro_latest = ahrs.get_gyro_latest();
    Vector3f acc_latest = ahrs.get_accel();

    Vector3f velocity_3d;
    if (ahrs.get_velocity_NED(velocity_3d)) {
        // Successfully retrieved the position
        // Use missile_position here
    } else {
        // Handle failure case
        printf("Failed to get missile velocity.\n");
    }
    // Gather necessary inputs for the controller
    double az_cmd = {1.0}; // Commanded vertical acceleration
    float acc_xyz_body[3] = {acc_latest.x, acc_latest.y, acc_latest.z};
    float az_body = acc_latest.z;
    float pitch_rate = gyro_latest.y;
    float speed_magnitude = {velocity_3d.length()}; //ahrs.get_velocity_NED();
    float alpha = {0.0};
    float beta = {0.0};
    double ay_cmd = {arg_Ay_cmd};
    float yaw_rate = gyro_latest.z;
    float roll_cmd = {0.0};
    float control_cmd[3]; // Output commands: roll, pitch, yaw

    // Call the custom controller
    controller.step(az_cmd, acc_xyz_body, pitch_rate, speed_magnitude, alpha,
                    beta, ay_cmd, yaw_rate, roll_cmd, control_cmd);

    if (control_cmd[1]*57.3 > 10.0f) {
    control_cmd[1] = 10.0f/57.3;
    } else if (control_cmd[1]*57.3 < -10.0f) {
    control_cmd[1] = -10.0f/57.3;
    }

    //float elevator_PWM = -(control_cmd[1]*1000)+1500;
    float elevator_PWM = (control_cmd[1]*57.3*500/10)+1500;

    //float aileron_servo = (control_cmd[0]*500/20)+1500;
    //SRV_Channels::set_output_scaled(SRV_Channel::k_aileron, 1500);
    //SRV_Channels::set_output_scaled(SRV_Channel::k_elevator, elevator_PWM);
    SRV_Channels::set_output_pwm(SRV_Channel::k_elevator, elevator_PWM);

    char msg[100];
    snprintf(msg, sizeof(msg), "Elevator PWM: %.2f, Control Cmd: %.6f, Speed Magnitude: %.2f, Az: %.2f, Body acc: %.2f", 
             elevator_PWM, control_cmd[1], speed_magnitude, az_cmd, az_body);
    //snprintf(msg, sizeof(msg), "Accel (x, y, z): %.2f, %.2f, %.2f",
      //   missile_position.x, missile_position.y, missile_position.z);

    // Send the message to MAVProxy
    gcs().send_text(MAV_SEVERITY_INFO, "%s", msg);


    // Extract the control commands
    //float roll_output = control_cmd[0];
    //float pitch_output = control_cmd[1];
    //float yaw_output = control_cmd[2];

    // Send commands to the motor mixer
    //AP_Motors::set_roll(roll_output);
    //AP_Motors::set_pitch(pitch_output);
    //AP_Motors::set_yaw(yaw_output);
}
