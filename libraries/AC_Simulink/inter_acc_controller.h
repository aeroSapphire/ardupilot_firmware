//
// File: inter_acc_controller.h
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
#ifndef RTW_HEADER_inter_acc_controller_h_
#define RTW_HEADER_inter_acc_controller_h_
#include "rtwtypes.h"
#include "inter_acc_controller_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model inter_acc_controller
class inter_acc_controller final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_inter_acc_controller_T {
    real32_T Integrator_DSTATE;        // '<S3>/Integrator'
    real32_T Integrator_DSTATE_l;      // '<S4>/Integrator'
    real32_T DiscreteTransferFcn_states;// '<S1>/Discrete Transfer Fcn'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_inter_acc_controller_T {
    real32_T control_cmd[3];           // '<Root>/control_cmd'
  };

  // Parameters (default storage)
  struct P_inter_acc_controller_T {
    real_T g_const_Value;              // Expression: -9.81
                                          //  Referenced by: '<Root>/g_const'

    real32_T Saturation_UpperSat;     // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<Root>/Saturation'

    real32_T Saturation_LowerSat;     // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<Root>/Saturation'

    real32_T Kp_Az_Gain;               // Computed Parameter: Kp_Az_Gain
                                          //  Referenced by: '<Root>/Kp_Az'

    real32_T Ki_pd_tableData[11];      // Computed Parameter: Ki_pd_tableData
                                          //  Referenced by: '<S3>/Ki_pd'

    real32_T Ki_pd_bp01Data[11];       // Computed Parameter: Ki_pd_bp01Data
                                          //  Referenced by: '<S3>/Ki_pd'

    real32_T Integrator_gainval;       // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S3>/Integrator'

    real32_T Integrator_IC;            // Computed Parameter: Integrator_IC
                                          //  Referenced by: '<S3>/Integrator'

    real32_T Integrator_UpperSat;     // Computed Parameter: Integrator_UpperSat
                                         //  Referenced by: '<S3>/Integrator'

    real32_T Integrator_LowerSat;     // Computed Parameter: Integrator_LowerSat
                                         //  Referenced by: '<S3>/Integrator'

    real32_T Kp_pd_tableData[11];      // Computed Parameter: Kp_pd_tableData
                                          //  Referenced by: '<S3>/Kp_pd'

    real32_T Kp_pd_bp01Data[11];       // Computed Parameter: Kp_pd_bp01Data
                                          //  Referenced by: '<S3>/Kp_pd'

    real32_T Gain_Gain;                // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S3>/Gain'

    real32_T Integrator_gainval_d;   // Computed Parameter: Integrator_gainval_d
                                        //  Referenced by: '<S4>/Integrator'

    real32_T Integrator_IC_n;          // Computed Parameter: Integrator_IC_n
                                          //  Referenced by: '<S4>/Integrator'

    real32_T Kp_tableData[11];         // Computed Parameter: Kp_tableData
                                          //  Referenced by: '<S4>/Kp'

    real32_T Kp_bp01Data[11];          // Computed Parameter: Kp_bp01Data
                                          //  Referenced by: '<S4>/Kp'

    real32_T Saturation1_UpperSat;   // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<Root>/Saturation1'

    real32_T Saturation1_LowerSat;   // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<Root>/Saturation1'

    real32_T Gain3_Gain;               // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<Root>/Gain3'

    real32_T Kd_Ay_Gain;               // Computed Parameter: Kd_Ay_Gain
                                          //  Referenced by: '<Root>/Kd_Ay'

    real32_T Gain5_Gain;               // Computed Parameter: Gain5_Gain
                                          //  Referenced by: '<Root>/Gain5'

    real32_T DiscreteTransferFcn_NumCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_NumCoef
                                 //  Referenced by: '<S1>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_DenCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_DenCoef
                                 //  Referenced by: '<S1>/Discrete Transfer Fcn'

    real32_T DiscreteTransferFcn_InitialStat;
                          // Computed Parameter: DiscreteTransferFcn_InitialStat
                             //  Referenced by: '<S1>/Discrete Transfer Fcn'

    real32_T Kp_Ay_Gain;               // Computed Parameter: Kp_Ay_Gain
                                          //  Referenced by: '<Root>/Kp_Ay'

    real32_T Ki_tableData[11];         // Computed Parameter: Ki_tableData
                                          //  Referenced by: '<S4>/Ki'

    real32_T Ki_bp01Data[11];          // Computed Parameter: Ki_bp01Data
                                          //  Referenced by: '<S4>/Ki'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_inter_acc_controller_T {
    const char_T * volatile errorStatus;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      struct {
        uint8_T TID[2];
      } TaskCounters;
    } Timing;
  };

  // Copy Constructor
  inter_acc_controller(inter_acc_controller const&) = delete;

  // Assignment Operator
  inter_acc_controller& operator= (inter_acc_controller const&) & = delete;

  // Move Constructor
  inter_acc_controller(inter_acc_controller &&) = delete;

  // Move Assignment Operator
  inter_acc_controller& operator= (inter_acc_controller &&) = delete;

  // Real-Time Model get method
  inter_acc_controller::RT_MODEL_inter_acc_controller_T * getRTM();

  // External outputs
  ExtY_inter_acc_controller_T inter_acc_controller_Y;

  // Tunable parameters
  static P_inter_acc_controller_T inter_acc_controller_P;

  // model initialize function
  void initialize();

  // model step function
  void step(real32_T arg_az_cmd, real32_T arg_acc_xyz_body[3], real32_T
            arg_pitch_rate, real32_T arg_speed_magnitude, real32_T arg_alpha,
            real32_T arg_beta, real32_T arg_ay_cmd, real32_T arg_yaw_rate,
            real32_T arg_roll_cmd, real32_T arg_control_cmd[3]);

  // model terminate function
  static void terminate();

  // Constructor
  inter_acc_controller();

  // Destructor
  ~inter_acc_controller();

  // private data and function members
 private:
  // Block states
  DW_inter_acc_controller_T inter_acc_controller_DW;

  // Real-Time Model
  RT_MODEL_inter_acc_controller_T inter_acc_controller_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'inter_acc_controller'
//  '<S1>'   : 'inter_acc_controller/Derivative'
//  '<S2>'   : 'inter_acc_controller/MATLAB Function'
//  '<S3>'   : 'inter_acc_controller/Pitch Damper'
//  '<S4>'   : 'inter_acc_controller/Yaw Damper'

#endif                                 // RTW_HEADER_inter_acc_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
