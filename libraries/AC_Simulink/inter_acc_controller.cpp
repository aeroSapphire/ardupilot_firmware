//
// File: inter_acc_controller.cpp
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
#include "inter_acc_controller.h"
#include "rtwtypes.h"
#include <cmath>
#include "inter_acc_controller_private.h"

static void rate_scheduler(inter_acc_controller::RT_MODEL_inter_acc_controller_T
  *const inter_acc_controller_M);
real32_T look1_iflf_binlxpw(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  real32_T yL_0d0;
  uint32_T iLeft;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

//
//         This function updates active task flag for each subrate.
//         The function is called at model base rate, hence the
//         generated code self-manages all its subrates.
//
static void rate_scheduler(inter_acc_controller::RT_MODEL_inter_acc_controller_T
  *const inter_acc_controller_M)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (inter_acc_controller_M->Timing.TaskCounters.TID[1])++;
  if ((inter_acc_controller_M->Timing.TaskCounters.TID[1]) > 3) {// Sample time: [0.01s, 0.0s] 
    inter_acc_controller_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// Model step function
void inter_acc_controller::step(real32_T arg_az_cmd, real32_T arg_acc_xyz_body[3],
  real32_T arg_pitch_rate, real32_T arg_speed_magnitude, real32_T arg_alpha,
  real32_T arg_beta, real32_T arg_ay_cmd, real32_T arg_yaw_rate, real32_T
  arg_roll_cmd, real32_T arg_control_cmd[3])
{
  int32_T i;
  real32_T Integrator_DSTATE_tmp_2[9];
  real32_T tmp[3];
  real32_T DiscreteTransferFcn_tmp;
  real32_T Integrator_DSTATE_tmp;
  real32_T Integrator_DSTATE_tmp_0;
  real32_T Integrator_DSTATE_tmp_1;
  real32_T Integrator_DSTATE_tmp_tmp;
  real32_T rtb_Ki;
  if ((&inter_acc_controller_M)->Timing.TaskCounters.TID[1] == 0) {
    // Outport: '<Root>/control_cmd' incorporates:
    //   DiscreteIntegrator: '<S3>/Integrator'
    //   DiscreteIntegrator: '<S4>/Integrator'
    //   Gain: '<S3>/Gain'
    //   Inport: '<Root>/pitch_rate'
    //   Inport: '<Root>/roll_cmd'
    //   Inport: '<Root>/speed_magnitude'
    //   Inport: '<Root>/yaw_rate'
    //   Lookup_n-D: '<S3>/Kp_pd'
    //   Lookup_n-D: '<S4>/Kp'
    //   Product: '<S3>/Product1'
    //   Product: '<S4>/Product1'
    //   Sum: '<S3>/Sum'
    //   Sum: '<S4>/Sum'

    inter_acc_controller_Y.control_cmd[0] = arg_roll_cmd;
    inter_acc_controller_Y.control_cmd[1] =
      (inter_acc_controller_DW.Integrator_DSTATE - arg_pitch_rate *
       look1_iflf_binlxpw(arg_speed_magnitude,
                          inter_acc_controller_P.Kp_pd_bp01Data,
                          inter_acc_controller_P.Kp_pd_tableData, 10U)) *
      inter_acc_controller_P.Gain_Gain;
    inter_acc_controller_Y.control_cmd[2] =
      inter_acc_controller_DW.Integrator_DSTATE_l - arg_yaw_rate *
      look1_iflf_binlxpw(arg_speed_magnitude, inter_acc_controller_P.Kp_bp01Data,
                         inter_acc_controller_P.Kp_tableData, 10U);

    // Saturate: '<Root>/Saturation1' incorporates:
    //   Inport: '<Root>/ay_cmd'

    if (arg_ay_cmd > inter_acc_controller_P.Saturation1_UpperSat) {
      Integrator_DSTATE_tmp = inter_acc_controller_P.Saturation1_UpperSat;
    } else if (arg_ay_cmd < inter_acc_controller_P.Saturation1_LowerSat) {
      Integrator_DSTATE_tmp = inter_acc_controller_P.Saturation1_LowerSat;
    } else {
      Integrator_DSTATE_tmp = arg_ay_cmd;
    }

    // Sum: '<Root>/Sum1' incorporates:
    //   Gain: '<Root>/Gain3'
    //   Inport: '<Root>/acc_xyz_body'
    //   Inport: '<Root>/yaw_rate'
    //   Saturate: '<Root>/Saturation1'
    //   Sum: '<Root>/Subtract1'

    rtb_Ki = Integrator_DSTATE_tmp - (arg_acc_xyz_body[1] - arg_yaw_rate) *
      inter_acc_controller_P.Gain3_Gain;

    // DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' incorporates:
    //   Gain: '<Root>/Gain5'
    //   Gain: '<Root>/Kd_Ay'

    DiscreteTransferFcn_tmp = (inter_acc_controller_P.Kd_Ay_Gain * rtb_Ki *
      inter_acc_controller_P.Gain5_Gain -
      inter_acc_controller_P.DiscreteTransferFcn_DenCoef[1] *
      inter_acc_controller_DW.DiscreteTransferFcn_states) /
      inter_acc_controller_P.DiscreteTransferFcn_DenCoef[0];

    // MATLAB Function: '<Root>/MATLAB Function' incorporates:
    //   Inport: '<Root>/alpha'
    //   Inport: '<Root>/beta'

    Integrator_DSTATE_tmp = std::cos(arg_beta);
    Integrator_DSTATE_tmp_0 = std::cos(arg_alpha);
    Integrator_DSTATE_tmp_1 = std::sin(arg_beta);
    Integrator_DSTATE_tmp_tmp = std::sin(arg_alpha);
    Integrator_DSTATE_tmp_2[0] = Integrator_DSTATE_tmp_0 * Integrator_DSTATE_tmp;
    Integrator_DSTATE_tmp_2[1] = Integrator_DSTATE_tmp_1;
    Integrator_DSTATE_tmp_2[2] = Integrator_DSTATE_tmp_tmp *
      Integrator_DSTATE_tmp;
    Integrator_DSTATE_tmp_2[3] = -Integrator_DSTATE_tmp_0 *
      Integrator_DSTATE_tmp_1;
    Integrator_DSTATE_tmp_2[4] = Integrator_DSTATE_tmp;
    Integrator_DSTATE_tmp_2[5] = -Integrator_DSTATE_tmp_tmp *
      Integrator_DSTATE_tmp_1;
    Integrator_DSTATE_tmp_2[6] = -Integrator_DSTATE_tmp_tmp;
    Integrator_DSTATE_tmp_2[7] = 0.0F;
    Integrator_DSTATE_tmp_2[8] = Integrator_DSTATE_tmp_0;

    // Math: '<Root>/Transpose' incorporates:
    //   Inport: '<Root>/acc_xyz_body'
    //   Product: '<Root>/MatrixMultiply'

    Integrator_DSTATE_tmp = arg_acc_xyz_body[1];
    Integrator_DSTATE_tmp_0 = arg_acc_xyz_body[0];
    Integrator_DSTATE_tmp_1 = arg_acc_xyz_body[2];

    // Product: '<Root>/MatrixMultiply' incorporates:
    //   Inport: '<Root>/acc_xyz_body'
    //   Math: '<Root>/Transpose'

    for (i = 0; i < 3; i++) {
      tmp[i] = (Integrator_DSTATE_tmp_2[3 * i + 1] * Integrator_DSTATE_tmp +
                Integrator_DSTATE_tmp_2[3 * i] * Integrator_DSTATE_tmp_0) +
        Integrator_DSTATE_tmp_2[3 * i + 2] * Integrator_DSTATE_tmp_1;
    }

    // Saturate: '<Root>/Saturation' incorporates:
    //   Inport: '<Root>/az_cmd'

    if (arg_az_cmd > inter_acc_controller_P.Saturation_UpperSat) {
      Integrator_DSTATE_tmp = inter_acc_controller_P.Saturation_UpperSat;
    } else if (arg_az_cmd < inter_acc_controller_P.Saturation_LowerSat) {
      Integrator_DSTATE_tmp = inter_acc_controller_P.Saturation_LowerSat;
    } else {
      Integrator_DSTATE_tmp = arg_az_cmd;
    }

    // Update for DiscreteIntegrator: '<S3>/Integrator' incorporates:
    //   Constant: '<Root>/g_const'
    //   Gain: '<Root>/Kp_Az'
    //   Inport: '<Root>/pitch_rate'
    //   Inport: '<Root>/speed_magnitude'
    //   Lookup_n-D: '<S3>/Ki_pd'
    //   Product: '<Root>/MatrixMultiply'
    //   Product: '<S3>/Product2'
    //   Saturate: '<Root>/Saturation'
    //   Sum: '<Root>/Subtract'
    //   Sum: '<Root>/Sum'
    //   Sum: '<S3>/Sum1'

    inter_acc_controller_DW.Integrator_DSTATE += ((Integrator_DSTATE_tmp -
      static_cast<real32_T>(tmp[2] - inter_acc_controller_P.g_const_Value)) *
      inter_acc_controller_P.Kp_Az_Gain - arg_pitch_rate) * look1_iflf_binlxpw
      (arg_speed_magnitude, inter_acc_controller_P.Ki_pd_bp01Data,
       inter_acc_controller_P.Ki_pd_tableData, 10U) *
      inter_acc_controller_P.Integrator_gainval;
    if (inter_acc_controller_DW.Integrator_DSTATE >=
        inter_acc_controller_P.Integrator_UpperSat) {
      inter_acc_controller_DW.Integrator_DSTATE =
        inter_acc_controller_P.Integrator_UpperSat;
    } else if (inter_acc_controller_DW.Integrator_DSTATE <=
               inter_acc_controller_P.Integrator_LowerSat) {
      inter_acc_controller_DW.Integrator_DSTATE =
        inter_acc_controller_P.Integrator_LowerSat;
    }

    // End of Update for DiscreteIntegrator: '<S3>/Integrator'

    // Update for DiscreteIntegrator: '<S4>/Integrator' incorporates:
    //   DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
    //   Gain: '<Root>/Kp_Ay'
    //   Inport: '<Root>/speed_magnitude'
    //   Inport: '<Root>/yaw_rate'
    //   Lookup_n-D: '<S4>/Ki'
    //   Product: '<S4>/Product2'
    //   Sum: '<Root>/Sum2'
    //   Sum: '<S4>/Sum1'

    inter_acc_controller_DW.Integrator_DSTATE_l +=
      (((inter_acc_controller_P.DiscreteTransferFcn_NumCoef[0] *
         DiscreteTransferFcn_tmp +
         inter_acc_controller_P.DiscreteTransferFcn_NumCoef[1] *
         inter_acc_controller_DW.DiscreteTransferFcn_states) +
        inter_acc_controller_P.Kp_Ay_Gain * rtb_Ki) - arg_yaw_rate) *
      look1_iflf_binlxpw(arg_speed_magnitude, inter_acc_controller_P.Ki_bp01Data,
                         inter_acc_controller_P.Ki_tableData, 10U) *
      inter_acc_controller_P.Integrator_gainval_d;

    // Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
    inter_acc_controller_DW.DiscreteTransferFcn_states = DiscreteTransferFcn_tmp;
  }

  rate_scheduler((&inter_acc_controller_M));

  // Copy value for root outport '<Root>/control_cmd' since it is accessed globally 
  {
    int32_T new_i;
    for (new_i = 0; new_i < 3; new_i++)
      arg_control_cmd[new_i] = inter_acc_controller_Y.control_cmd[new_i];
  }
}

// Model initialize function
void inter_acc_controller::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<S3>/Integrator'
  inter_acc_controller_DW.Integrator_DSTATE =
    inter_acc_controller_P.Integrator_IC;

  // InitializeConditions for DiscreteIntegrator: '<S4>/Integrator'
  inter_acc_controller_DW.Integrator_DSTATE_l =
    inter_acc_controller_P.Integrator_IC_n;

  // InitializeConditions for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
  inter_acc_controller_DW.DiscreteTransferFcn_states =
    inter_acc_controller_P.DiscreteTransferFcn_InitialStat;
}

// Model terminate function
void inter_acc_controller::terminate()
{
  // (no terminate code required)
}

// Constructor
inter_acc_controller::inter_acc_controller() :
  inter_acc_controller_Y(),
  inter_acc_controller_DW(),
  inter_acc_controller_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
inter_acc_controller::~inter_acc_controller() = default;

// Real-Time Model get method
inter_acc_controller::RT_MODEL_inter_acc_controller_T * inter_acc_controller::
  getRTM()
{
  return (&inter_acc_controller_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
