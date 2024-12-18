//
// File: ert_main.cpp
//
// Code generated for Simulink model 'inter_acc_controller'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Thu Dec 12 21:26:49 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include <stdio.h>              // This example main program uses printf/fflush
#include "inter_acc_controller.h"      // Model header file

static inter_acc_controller inter_acc_controller_Obj;// Instance of model class

// '<Root>/az_cmd'
static real32_T arg_az_cmd{ 0.0F };

// '<Root>/acc_xyz_body'
static real32_T arg_acc_xyz_body[3]{ 0.0F, 0.0F, 0.0F };

// '<Root>/pitch_rate'
static real32_T arg_pitch_rate{ 0.0F };

// '<Root>/speed_magnitude'
static real32_T arg_speed_magnitude{ 0.0F };

// '<Root>/alpha'
static real32_T arg_alpha{ 0.0F };

// '<Root>/beta'
static real32_T arg_beta{ 0.0F };

// '<Root>/ay_cmd'
static real32_T arg_ay_cmd{ 0.0F };

// '<Root>/yaw_rate'
static real32_T arg_yaw_rate{ 0.0F };

// '<Root>/roll_cmd'
static real32_T arg_roll_cmd{ 0.0F };

// '<Root>/control_cmd'
static real32_T arg_control_cmd[3];

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag{ false };

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(inter_acc_controller_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  inter_acc_controller_Obj.step(arg_az_cmd, arg_acc_xyz_body, arg_pitch_rate,
    arg_speed_magnitude, arg_alpha, arg_beta, arg_ay_cmd, arg_yaw_rate,
    arg_roll_cmd, arg_control_cmd);

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example main function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific. This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  // Unused arguments
  (void)(argc);
  (void)(argv);

  // Initialize model
  inter_acc_controller_Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.0025 seconds (base rate of the model) here.
  //  The call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((nullptr));
  while (rtmGetErrorStatus(inter_acc_controller_Obj.getRTM()) == (nullptr)) {
    //  Perform application tasks here
  }

  // Terminate model
  inter_acc_controller_Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
