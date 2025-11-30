/*
 * File: TCM.h
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

#ifndef TCM_h_
#define TCM_h_
#ifndef TCM_Final_COMMON_INCLUDES_
#define TCM_Final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* TCM_Final_COMMON_INCLUDES_ */

/* Block signals for system '<Root>/TCM' */
typedef struct {
  uint8_T DownShift;                   /* '<S1>/Driver_Mode' */
  uint8_T UpShift;                     /* '<S1>/Driver_Mode' */
} B_TCM_TCM_Final_T;

/* Block states (default storage) for system '<Root>/TCM' */
typedef struct {
  uint8_T is_active_c3_TCC_Control_Librar;/* '<S1>/TCC_Control' */
  uint8_T is_c3_TCC_Control_Library;   /* '<S1>/TCC_Control' */
  uint8_T is_active_c3_Hydraulic_Pressure;/* '<S1>/Hydraulic_Pressure_Control' */
  uint8_T N;                           /* '<S1>/Gear_Selection' */
  uint8_T R;                           /* '<S1>/Gear_Selection' */
  uint8_T Fifth;                       /* '<S1>/Gear_Selection' */
  uint8_T First;                       /* '<S1>/Gear_Selection' */
  uint8_T Fourth;                      /* '<S1>/Gear_Selection' */
  uint8_T Second;                      /* '<S1>/Gear_Selection' */
  uint8_T Sixth;                       /* '<S1>/Gear_Selection' */
  uint8_T Third;                       /* '<S1>/Gear_Selection' */
  uint8_T is_active_c3_Gear_Selection_Lib;/* '<S1>/Gear_Selection' */
  uint8_T is_c3_Gear_Selection_Library;/* '<S1>/Gear_Selection' */
  uint8_T is_Drive;                    /* '<S1>/Gear_Selection' */
  uint8_T temporalCounter_i1;          /* '<S1>/Gear_Selection' */
  uint8_T is_active_c3_Drive_Mode_Librery;/* '<S1>/Driver_Mode' */
  uint8_T is_c3_Drive_Mode_Librery;    /* '<S1>/Driver_Mode' */
} DW_TCM_TCM_Final_T;

extern void TCM_Final_TCM_Init(uint8_T *rty_Current_Gear, uint8_T
  *rty_Shift_Solenoid_A, uint8_T *rty_Shift_Solenoid_B, uint8_T
  *rty_Shift_Solenoid_C, uint8_T *rty_Shift_Solenoid_D, uint8_T
  *rty_Shift_Solenoid_E, uint8_T *rty_TCC_Control_Solenoid, uint8_T
  *rty_Line_Pressure_Control_Solen);
extern void TCM_Final_TCM(uint8_T rtu_Brake_Pedal_Switch, uint8_T
  rtu_Gear_Lever_Position, uint8_T rtu_Vehicle_Speed_Reference, uint8_T
  rtu_Driver_Mode_Selection, uint16_T rtu_Engine_RPM, uint8_T
  rtu_Throttle_Position_Sensor, int8_T rtu_Transmission_Fluid_Temp, uint16_T
  rtu_Output_Speed_Sensor, int16_T rtu_Engine_Torque_Actual, uint16_T
  rtu_Turbine_Speed_Sensor, uint8_T *rty_Current_Gear, uint8_T
  *rty_Shift_Solenoid_A, uint8_T *rty_Shift_Solenoid_B, uint8_T
  *rty_Shift_Solenoid_C, uint8_T *rty_Shift_Solenoid_D, uint8_T
  *rty_Shift_Solenoid_E, uint8_T *rty_TCC_Control_Solenoid, uint8_T
  *rty_Line_Pressure_Control_Solen, B_TCM_TCM_Final_T *localB,
  DW_TCM_TCM_Final_T *localDW);

#endif                                 /* TCM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
