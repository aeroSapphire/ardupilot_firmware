#pragma once

#include "AC_CustomControl_Backend.h"
#include <AC_Simulink/inter_acc_controller.h>
#include <AP_InertialSensor/AP_InertialSensor.h>
#include <AP_InertialNav/AP_InertialNav.h>

#ifndef CUSTOMCONTROL_Tracker_ENABLED
    #define CUSTOMCONTROL_Tracker_ENABLED AP_CUSTOMCONTROL_ENABLED
#endif

#if CUSTOMCONTROL_Tracker_ENABLED

class AC_CustomControl_Tracker : public AC_CustomControl_Backend {
public:
    AC_CustomControl_Tracker(AC_CustomControl& frontend, AP_AHRS_View*& ahrs, AC_AttitudeControl*& att_control, AP_MotorsMulticopter*& motors, float dt);


    Vector3f update(void) override;
    void reset(void) override;

    inter_acc_controller acc_controller;

    // user settable parameters
    static const struct AP_Param::GroupInfo var_info[];

protected:
    // declare parameters here
    AP_Float param1;
    AP_Float param2;
    AP_Float param3;
};

#endif
