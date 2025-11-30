/*
 * File: TCM_Final.h
 *
 * Code generated for Simulink model 'TCM_Final'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Nov 28 02:40:44 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef TCM_Final_h_
#define TCM_Final_h_
#ifndef TCM_Final_COMMON_INCLUDES_
#define TCM_Final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* TCM_Final_COMMON_INCLUDES_ */

#include "TCM_Final_types.h"
#include "TCM.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  B_TCM_TCM_Final_T TCM;               /* '<Root>/TCM' */
} B_TCM_Final_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_TCM_TCM_Final_T TCM;              /* '<Root>/TCM' */
} DW_TCM_Final_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [0.70 0.75 0.80 0.85 0.90 0.95;
     0.78 0.82 0.86 0.90 0.94 0.98;
     0.85 0.88 0.92 0.96 1.00 1.04;
     0.90 0.94 0.98 1.02 1.06 1.10;
     0.92 0.96 1.00 1.04 1.08 1.12;
     0.88 0.92 0.96 1.00 1.04 1.08;
     0.80 0.84 0.88 0.92 0.96 1.00]

   * Referenced by: '<S9>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_tableData[42];

  /* Expression: [-40 0 40 80 100 120 150]
   * Referenced by: '<S9>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_bp01Data[7];

  /* Expression: [0 20 40 60 80 100]
   * Referenced by: '<S9>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_bp02Data[6];

  /* Expression: [  8  7  6  5  4  3;
     12 10  9  8  7  6;
     20 18 16 14 12 10;
     30 26 22 18 16 14;
     42 36 30 26 22 18;
     56 48 42 36 32 28;
     68 60 52 46 40 34;
     82 72 64 56 48 42;
     92 82 74 66 58 50;
     100 92 84 76 68 60]

   * Referenced by: '<S9>/LUT1 — P_ff_base'
   */
  real_T LUT1P_ff_base_tableData[60];

  /* Expression: [-50 0 50 100 150 200 250 300 350 400]

   * Referenced by: '<S9>/LUT1 — P_ff_base'
   */
  real_T LUT1P_ff_base_bp01Data[10];

  /* Pooled Parameter (Expression: [49 50 51 52 53 54])
   * Referenced by:
   *   '<S9>/LUT1 — P_ff_base'
   *   '<S10>/2-D Lookup Table1'
   */
  real_T pooled1[6];

  /* Expression: [ 8  10  12  15  18;
     18  22  28  34  40;
     30  36  44  52  60;
     45  54  64  76  88;
     60  72  84  92  94]

   * Referenced by: '<S9>/PWM_EPC'
   */
  real_T PWM_EPC_tableData[25];

  /* Expression: [20 40 60 80 100]
   * Referenced by: '<S9>/PWM_EPC'
   */
  real_T PWM_EPC_bp01Data[5];

  /* Expression: [0.70 0.85 1.00 1.15 1.30]
   * Referenced by: '<S9>/PWM_EPC'
   */
  real_T PWM_EPC_bp02Data[5];

  /* Expression: [-200 -150 -100 -50 0 50 100 150 200 300]

   * Referenced by: '<S10>/2-D Lookup Table1'
   */
  real_T uDLookupTable1_bp02Data_c[10];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/Eco Mode Downshift'
   *   '<S6>/Eco Mode Upshift'
   *   '<S7>/Normal dowshift'
   *   '<S7>/Normal upshift'
   *   '<S8>/Sport Mode Downshift'
   *   '<S8>/Sport Mode Upshift'
   */
  uint32_T pooled2[2];

  /* Computed Parameter: uDLookupTable1_maxIndex
   * Referenced by: '<S9>/2-D Lookup Table1'
   */
  uint32_T uDLookupTable1_maxIndex[2];

  /* Computed Parameter: LUT1P_ff_base_maxIndex
   * Referenced by: '<S9>/LUT1 — P_ff_base'
   */
  uint32_T LUT1P_ff_base_maxIndex[2];

  /* Computed Parameter: PWM_EPC_maxIndex
   * Referenced by: '<S9>/PWM_EPC'
   */
  uint32_T PWM_EPC_maxIndex[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S10>/2-D Lookup Table'
   *   '<S10>/2-D Lookup Table1'
   */
  uint32_T pooled3[2];

  /* Computed Parameter: uDLookupTable2_maxIndex
   * Referenced by: '<S10>/2-D Lookup Table2'
   */
  uint32_T uDLookupTable2_maxIndex[2];

  /* Computed Parameter: uDLookupTable_tableData
   * Referenced by: '<S10>/2-D Lookup Table'
   */
  int16_T uDLookupTable_tableData[60];

  /* Computed Parameter: uDLookupTable_bp02Data
   * Referenced by: '<S10>/2-D Lookup Table'
   */
  int16_T uDLookupTable_bp02Data[10];

  /* Computed Parameter: uDLookupTable1_tableData_k
   * Referenced by: '<S10>/2-D Lookup Table1'
   */
  int16_T uDLookupTable1_tableData_k[60];

  /* Computed Parameter: EcoModeUpshift_tableData
   * Referenced by: '<S6>/Eco Mode Upshift'
   */
  uint16_T EcoModeUpshift_tableData[143];

  /* Computed Parameter: EcoModeDownshift_tableData
   * Referenced by: '<S6>/Eco Mode Downshift'
   */
  uint16_T EcoModeDownshift_tableData[143];

  /* Computed Parameter: Normalupshift_tableData
   * Referenced by: '<S7>/Normal upshift'
   */
  uint16_T Normalupshift_tableData[143];

  /* Computed Parameter: Normaldowshift_tableData
   * Referenced by: '<S7>/Normal dowshift'
   */
  uint16_T Normaldowshift_tableData[143];

  /* Computed Parameter: SportModeUpshift_tableData
   * Referenced by: '<S8>/Sport Mode Upshift'
   */
  uint16_T SportModeUpshift_tableData[143];

  /* Computed Parameter: SportModeDownshift_tableData
   * Referenced by: '<S8>/Sport Mode Downshift'
   */
  uint16_T SportModeDownshift_tableData[143];

  /* Computed Parameter: uDLookupTable2_tableData
   * Referenced by: '<S10>/2-D Lookup Table2'
   */
  uint16_T uDLookupTable2_tableData[100];

  /* Pooled Parameter (Expression: [0 1 2 3 4 5 6 7 8 9]
     )
   * Referenced by: '<S10>/2-D Lookup Table2'
   */
  uint16_T pooled4[10];

  /* Pooled Parameter (Expression: [0 20 40 60 80 100 120 140 160 180 200 220 240]
     )
   * Referenced by:
   *   '<S6>/Eco Mode Downshift'
   *   '<S6>/Eco Mode Upshift'
   *   '<S7>/Normal dowshift'
   *   '<S7>/Normal upshift'
   *   '<S8>/Sport Mode Downshift'
   *   '<S8>/Sport Mode Upshift'
   */
  uint8_T pooled6[13];

  /* Pooled Parameter (Expression: [0 10 20 30 40 50 60 70 80 90 100]
     )
   * Referenced by:
   *   '<S6>/Eco Mode Downshift'
   *   '<S6>/Eco Mode Upshift'
   *   '<S7>/Normal dowshift'
   *   '<S7>/Normal upshift'
   *   '<S8>/Sport Mode Downshift'
   *   '<S8>/Sport Mode Upshift'
   */
  uint8_T pooled7[11];

  /* Computed Parameter: uDLookupTable_bp01Data
   * Referenced by: '<S10>/2-D Lookup Table'
   */
  uint8_T uDLookupTable_bp01Data[6];
} ConstP_TCM_Final_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T Brake_Pedal_Switch;          /* '<Root>/Brake_Pedal_Switch' */
  uint8_T Gear_Lever_Position;         /* '<Root>/Gear_Lever_Position' */
  uint8_T Vehicle_Speed_Reference;     /* '<Root>/Vehicle_Speed_Reference' */
  uint8_T Driver_Mode_Selection;       /* '<Root>/Driver_Mode_Selection' */
  uint16_T Engine_RPM;                 /* '<Root>/Engine_RPM' */
  uint8_T Throttle_Position_Sensor;    /* '<Root>/Throttle_Position_Sensor' */
  int8_T Transmission_Fluid_Temp;      /* '<Root>/Transmission_Fluid_Temp' */
  uint16_T Output_Speed_Sensor;        /* '<Root>/Output_Speed_Sensor' */
  int16_T Engine_Torque_Actual;        /* '<Root>/Engine_Torque_Actual' */
  uint16_T Turbine_Speed_Sensor;       /* '<Root>/Turbine_Speed_Sensor' */
} ExtU_TCM_Final_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T Current_Gear;                /* '<Root>/Current_Gear' */
  uint8_T Shift_Solenoid_A;            /* '<Root>/Shift_Solenoid_A' */
  uint8_T Shift_Solenoid_B;            /* '<Root>/Shift_Solenoid_B' */
  uint8_T Shift_Solenoid_C;            /* '<Root>/Shift_Solenoid_C' */
  uint8_T Shift_Solenoid_D;            /* '<Root>/Shift_Solenoid_D' */
  uint8_T Shift_Solenoid_E;            /* '<Root>/Shift_Solenoid_E' */
  uint8_T TCC_Control_Solenoid;        /* '<Root>/TCC_Control_Solenoid' */
  uint8_T Line_Pressure_Control_Solenoid;
                                   /* '<Root>/Line_Pressure_Control_Solenoid' */
} ExtY_TCM_Final_T;

/* Real-time Model Data Structure */
struct tag_RTM_TCM_Final_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_TCM_Final_T TCM_Final_B;

/* Block states (default storage) */
extern DW_TCM_Final_T TCM_Final_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_TCM_Final_T TCM_Final_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TCM_Final_T TCM_Final_Y;

/* Constant parameters (default storage) */
extern const ConstP_TCM_Final_T TCM_Final_ConstP;

/* Model entry point functions */
extern void TCM_Final_initialize(void);
extern void TCM_Final_step(void);
extern void TCM_Final_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TCM_Final_T *const TCM_Final_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TCM_Final'
 * '<S1>'   : 'TCM_Final/TCM'
 * '<S2>'   : 'TCM_Final/TCM/Driver_Mode'
 * '<S3>'   : 'TCM_Final/TCM/Gear_Selection'
 * '<S4>'   : 'TCM_Final/TCM/Hydraulic_Pressure_Control'
 * '<S5>'   : 'TCM_Final/TCM/TCC_Control'
 * '<S6>'   : 'TCM_Final/TCM/Driver_Mode/EcoF'
 * '<S7>'   : 'TCM_Final/TCM/Driver_Mode/NormalF'
 * '<S8>'   : 'TCM_Final/TCM/Driver_Mode/SportF'
 * '<S9>'   : 'TCM_Final/TCM/Hydraulic_Pressure_Control/EPC_F'
 * '<S10>'  : 'TCM_Final/TCM/TCC_Control/SlipMode_F'
 */
#endif                                 /* TCM_Final_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
