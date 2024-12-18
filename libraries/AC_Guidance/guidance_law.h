//
// File: guidance_law.h
//
// Code generated for Simulink model 'guidance_law'.
//
// Model version                  : 1.1
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Mon Dec 16 21:47:01 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_guidance_law_h_
#define RTW_HEADER_guidance_law_h_
#include "rtwtypes.h"
#include "guidance_law_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model guidance_law
class guidance_law final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_guidance_law_T {
    real32_T UD_DSTATE;                // '<S5>/UD'
    real32_T UD_DSTATE_n;              // '<S6>/UD'
    real32_T UD_DSTATE_b;              // '<S3>/UD'
    real32_T UD_DSTATE_bn;             // '<S4>/UD'
  };

  // Parameters (default storage)
  struct P_guidance_law_T {
    real32_T DiscreteDerivative_ICPrevScaled;
                              // Mask Parameter: DiscreteDerivative_ICPrevScaled
                                 //  Referenced by: '<S5>/UD'

    real32_T DiscreteDerivative1_ICPrevScale;
                              // Mask Parameter: DiscreteDerivative1_ICPrevScale
                                 //  Referenced by: '<S6>/UD'

    real32_T DiscreteDerivative_ICPrevScal_g;
                              // Mask Parameter: DiscreteDerivative_ICPrevScal_g
                                 //  Referenced by: '<S3>/UD'

    real32_T DiscreteDerivative1_ICPrevSca_e;
                              // Mask Parameter: DiscreteDerivative1_ICPrevSca_e
                                 //  Referenced by: '<S4>/UD'

    real_T NPNconst_Value;             // Expression: -5
                                          //  Referenced by: '<S2>/N' (PN const)'

    real_T N_Value;                    // Expression: -3
                                          //  Referenced by: '<S1>/N''

    real32_T Gain1_Gain;               // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S2>/Gain1'

    real32_T TSamp_WtEt;               // Computed Parameter: TSamp_WtEt
                                          //  Referenced by: '<S5>/TSamp'

    real32_T TSamp_WtEt_m;             // Computed Parameter: TSamp_WtEt_m
                                          //  Referenced by: '<S6>/TSamp'

    real32_T Gain_Gain;                // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S2>/Gain'

    real32_T TSamp_WtEt_l;             // Computed Parameter: TSamp_WtEt_l
                                          //  Referenced by: '<S3>/TSamp'

    real32_T TSamp_WtEt_h;             // Computed Parameter: TSamp_WtEt_h
                                          //  Referenced by: '<S4>/TSamp'

    real32_T Gain_Gain_c;              // Computed Parameter: Gain_Gain_c
                                          //  Referenced by: '<S1>/Gain'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_guidance_law_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  guidance_law(guidance_law const&) = delete;

  // Assignment Operator
  guidance_law& operator= (guidance_law const&) & = delete;

  // Move Constructor
  guidance_law(guidance_law &&) = delete;

  // Move Assignment Operator
  guidance_law& operator= (guidance_law &&) = delete;

  // Real-Time Model get method
  guidance_law::RT_MODEL_guidance_law_T * getRTM();

  // Tunable parameters
  static P_guidance_law_T guidance_law_P;

  // model initialize function
  void initialize();

  // model step function
  void step(real32_T arg_POS_M[3], real32_T arg_POS_T[3], real_T *arg_Az_cmd,
            real_T *arg_Ay_cmd);

  // model terminate function
  static void terminate();

  // Constructor
  guidance_law();

  // Destructor
  ~guidance_law();

  // private data and function members
 private:
  // Block states
  DW_guidance_law_T guidance_law_DW;

  // Real-Time Model
  RT_MODEL_guidance_law_T guidance_law_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/Data Type Duplicate' : Unused code path elimination
//  Block '<S4>/Data Type Duplicate' : Unused code path elimination
//  Block '<S5>/Data Type Duplicate' : Unused code path elimination
//  Block '<S6>/Data Type Duplicate' : Unused code path elimination
//  Block '<S7>/Data Type Duplicate' : Unused code path elimination
//  Block '<S7>/Diff' : Unused code path elimination
//  Block '<S7>/TSamp' : Unused code path elimination
//  Block '<S7>/UD' : Unused code path elimination
//  Block '<S8>/Compare' : Unused code path elimination
//  Block '<S8>/Constant' : Unused code path elimination


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
//  '<Root>' : 'guidance_law'
//  '<S1>'   : 'guidance_law/PN GUIDANCE LAW (Cross range)'
//  '<S2>'   : 'guidance_law/PN GUIDANCE LAW (Range)'
//  '<S3>'   : 'guidance_law/PN GUIDANCE LAW (Cross range)/Discrete Derivative'
//  '<S4>'   : 'guidance_law/PN GUIDANCE LAW (Cross range)/Discrete Derivative1'
//  '<S5>'   : 'guidance_law/PN GUIDANCE LAW (Range)/Discrete Derivative'
//  '<S6>'   : 'guidance_law/PN GUIDANCE LAW (Range)/Discrete Derivative1'
//  '<S7>'   : 'guidance_law/PN GUIDANCE LAW (Range)/Discrete Derivative2'
//  '<S8>'   : 'guidance_law/PN GUIDANCE LAW (Range)/|R'|>0'

#endif                                 // RTW_HEADER_guidance_law_h_

//
// File trailer for generated code.
//
// [EOF]
//
