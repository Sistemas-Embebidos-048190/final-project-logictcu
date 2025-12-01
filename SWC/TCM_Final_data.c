/*
 * File: TCM_Final_data.c
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

#include "TCM_Final.h"

/* Constant parameters (default storage) */
const ConstP_TCM_Final_T TCM_Final_ConstP = {
  /* Expression: [0.70 0.75 0.80 0.85 0.90 0.95;
     0.78 0.82 0.86 0.90 0.94 0.98;
     0.85 0.88 0.92 0.96 1.00 1.04;
     0.90 0.94 0.98 1.02 1.06 1.10;
     0.92 0.96 1.00 1.04 1.08 1.12;
     0.88 0.92 0.96 1.00 1.04 1.08;
     0.80 0.84 0.88 0.92 0.96 1.00]

   * Referenced by: '<S9>/2-D Lookup Table1'
   */
  { 0.7, 0.78, 0.85, 0.9, 0.92, 0.88, 0.8, 0.75, 0.82, 0.88, 0.94, 0.96, 0.92,
    0.84, 0.8, 0.86, 0.92, 0.98, 1.0, 0.96, 0.88, 0.85, 0.9, 0.96, 1.02, 1.04,
    1.0, 0.92, 0.9, 0.94, 1.0, 1.06, 1.08, 1.04, 0.96, 0.95, 0.98, 1.04, 1.1,
    1.12, 1.08, 1.0 },

  /* Expression: [-40 0 40 80 100 120 150]
   * Referenced by: '<S9>/2-D Lookup Table1'
   */
  { -40.0, 0.0, 40.0, 80.0, 100.0, 120.0, 150.0 },

  /* Expression: [0 20 40 60 80 100]
   * Referenced by: '<S9>/2-D Lookup Table1'
   */
  { 0.0, 20.0, 40.0, 60.0, 80.0, 100.0 },

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
  { 8.0, 12.0, 20.0, 30.0, 42.0, 56.0, 68.0, 82.0, 92.0, 100.0, 7.0, 10.0, 18.0,
    26.0, 36.0, 48.0, 60.0, 72.0, 82.0, 92.0, 6.0, 9.0, 16.0, 22.0, 30.0, 42.0,
    52.0, 64.0, 74.0, 84.0, 5.0, 8.0, 14.0, 18.0, 26.0, 36.0, 46.0, 56.0, 66.0,
    76.0, 4.0, 7.0, 12.0, 16.0, 22.0, 32.0, 40.0, 48.0, 58.0, 68.0, 3.0, 6.0,
    10.0, 14.0, 18.0, 28.0, 34.0, 42.0, 50.0, 60.0 },

  /* Expression: [-50 0 50 100 150 200 250 300 350 400]

   * Referenced by: '<S9>/LUT1 — P_ff_base'
   */
  { -50.0, 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0 },

  /* Pooled Parameter (Expression: [49 50 51 52 53 54])
   * Referenced by:
   *   '<S9>/LUT1 — P_ff_base'
   *   '<S10>/2-D Lookup Table1'
   */
  { 49.0, 50.0, 51.0, 52.0, 53.0, 54.0 },

  /* Expression: [ 8  10  12  15  18;
     18  22  28  34  40;
     30  36  44  52  60;
     45  54  64  76  88;
     60  72  84  92  94]

   * Referenced by: '<S9>/PWM_EPC'
   */
  { 8.0, 18.0, 30.0, 45.0, 60.0, 10.0, 22.0, 36.0, 54.0, 72.0, 12.0, 28.0, 44.0,
    64.0, 84.0, 15.0, 34.0, 52.0, 76.0, 92.0, 18.0, 40.0, 60.0, 88.0, 94.0 },

  /* Expression: [20 40 60 80 100]
   * Referenced by: '<S9>/PWM_EPC'
   */
  { 20.0, 40.0, 60.0, 80.0, 100.0 },

  /* Expression: [0.70 0.85 1.00 1.15 1.30]
   * Referenced by: '<S9>/PWM_EPC'
   */
  { 0.7, 0.85, 1.0, 1.15, 1.3 },

  /* Expression: [-200 -150 -100 -50 0 50 100 150 200 300]

   * Referenced by: '<S10>/2-D Lookup Table1'
   */
  { -200.0, -150.0, -100.0, -50.0, 0.0, 50.0, 100.0, 150.0, 200.0, 300.0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S6>/Eco Mode Downshift'
   *   '<S6>/Eco Mode Upshift'
   *   '<S7>/Normal dowshift'
   *   '<S7>/Normal upshift'
   *   '<S8>/Sport Mode Downshift'
   *   '<S8>/Sport Mode Upshift'
   */
  { 12U, 10U },

  /* Computed Parameter: uDLookupTable1_maxIndex
   * Referenced by: '<S9>/2-D Lookup Table1'
   */
  { 6U, 5U },

  /* Computed Parameter: LUT1P_ff_base_maxIndex
   * Referenced by: '<S9>/LUT1 — P_ff_base'
   */
  { 9U, 5U },

  /* Computed Parameter: PWM_EPC_maxIndex
   * Referenced by: '<S9>/PWM_EPC'
   */
  { 4U, 4U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S10>/2-D Lookup Table'
   *   '<S10>/2-D Lookup Table1'
   */
  { 5U, 9U },

  /* Computed Parameter: uDLookupTable2_maxIndex
   * Referenced by: '<S10>/2-D Lookup Table2'
   */
  { 9U, 9U },

  /* Computed Parameter: uDLookupTable_tableData
   * Referenced by: '<S10>/2-D Lookup Table'
   */
  { 0, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6, 7, 3, 4,
    5, 6, 7, 8, 4, 5, 6, 7, 8, 9, 5, 6, 6, 7, 8, 9, 5, 6, 7, 8, 9, 9, 6, 7, 8, 9,
    9, 9, 6, 7, 8, 9, 9, 9 },

  /* Computed Parameter: uDLookupTable_bp02Data
   * Referenced by: '<S10>/2-D Lookup Table'
   */
  { -50, 0, 50, 100, 150, 200, 250, 300, 350, 400 },

  /* Computed Parameter: uDLookupTable1_tableData_k
   * Referenced by: '<S10>/2-D Lookup Table1'
   */
  { 0, 0, 0, 1, 2, 3, 0, 1, 1, 2, 3, 4, 1, 2, 2, 3, 4, 5, 2, 3, 4, 4, 5, 6, 3, 4,
    5, 6, 7, 7, 5, 6, 6, 7, 8, 8, 6, 7, 7, 8, 8, 9, 7, 8, 8, 8, 9, 9, 8, 9, 9, 9,
    9, 9, 9, 9, 9, 9, 9, 9 },

  /* Computed Parameter: EcoModeUpshift_tableData
   * Referenced by: '<S6>/Eco Mode Upshift'
   */
  { 1200U, 1250U, 1300U, 1400U, 1500U, 1600U, 1700U, 1850U, 2000U, 2200U, 2400U,
    2600U, 2800U, 1250U, 1300U, 1350U, 1450U, 1550U, 1680U, 1800U, 1960U, 2130U,
    2340U, 2560U, 2780U, 3000U, 1300U, 1350U, 1420U, 1550U, 1670U, 1820U, 1960U,
    2140U, 2330U, 2560U, 2800U, 3040U, 3280U, 1350U, 1400U, 1500U, 1650U, 1790U,
    1970U, 2130U, 2330U, 2540U, 2790U, 3050U, 3310U, 3560U, 1400U, 1450U, 1580U,
    1760U, 1930U, 2130U, 2310U, 2530U, 2760U, 3030U, 3310U, 3590U, 3850U, 1450U,
    1500U, 1660U, 1870U, 2070U, 2300U, 2490U, 2740U, 2980U, 3270U, 3570U, 3870U,
    4140U, 1500U, 1550U, 1740U, 1980U, 2220U, 2470U, 2680U, 2960U, 3210U, 3520U,
    3840U, 4160U, 4440U, 1550U, 1600U, 1820U, 2090U, 2370U, 2640U, 2870U, 3180U,
    3440U, 3770U, 4110U, 4450U, 4740U, 1600U, 1650U, 1900U, 2200U, 2520U, 2810U,
    3060U, 3400U, 3670U, 4020U, 4380U, 4740U, 5040U, 1650U, 1700U, 1980U, 2310U,
    2670U, 2980U, 3250U, 3620U, 3900U, 4270U, 4650U, 5030U, 5340U, 1700U, 1750U,
    2050U, 2400U, 2820U, 3150U, 3440U, 3840U, 4130U, 4520U, 4920U, 5320U, 5640U
  },

  /* Computed Parameter: EcoModeDownshift_tableData
   * Referenced by: '<S6>/Eco Mode Downshift'
   */
  { 900U, 920U, 950U, 1000U, 1100U, 1200U, 1300U, 1400U, 1500U, 1600U, 1800U,
    2000U, 2200U, 920U, 940U, 980U, 1040U, 1140U, 1240U, 1340U, 1440U, 1540U,
    1650U, 1860U, 2060U, 2280U, 950U, 970U, 1050U, 1100U, 1220U, 1340U, 1460U,
    1580U, 1700U, 1830U, 2060U, 2280U, 2520U, 1000U, 1020U, 1120U, 1180U, 1320U,
    1460U, 1600U, 1740U, 1880U, 2020U, 2270U, 2510U, 2760U, 1050U, 1070U, 1200U,
    1280U, 1440U, 1580U, 1740U, 1900U, 2060U, 2220U, 2490U, 2740U, 3000U, 1100U,
    1120U, 1280U, 1380U, 1560U, 1700U, 1880U, 2060U, 2240U, 2420U, 2710U, 2970U,
    3240U, 1150U, 1170U, 1360U, 1480U, 1680U, 1820U, 2020U, 2220U, 2420U, 2620U,
    2930U, 3200U, 3480U, 1200U, 1220U, 1440U, 1580U, 1800U, 1940U, 2160U, 2380U,
    2600U, 2820U, 3150U, 3430U, 3720U, 1250U, 1270U, 1520U, 1680U, 1920U, 2060U,
    2300U, 2540U, 2780U, 3020U, 3370U, 3660U, 3960U, 1300U, 1320U, 1600U, 1780U,
    2040U, 2180U, 2440U, 2700U, 2960U, 3220U, 3590U, 3890U, 4200U, 1350U, 1370U,
    1650U, 1880U, 2160U, 2300U, 2580U, 2860U, 3140U, 3420U, 3810U, 4120U, 4440U
  },

  /* Computed Parameter: Normalupshift_tableData
   * Referenced by: '<S7>/Normal upshift'
   */
  { 1500U, 1600U, 1700U, 1820U, 1950U, 2100U, 2260U, 2440U, 2620U, 2820U, 3040U,
    3260U, 3500U, 1600U, 1700U, 1820U, 1940U, 2080U, 2240U, 2420U, 2620U, 2820U,
    3040U, 3280U, 3520U, 3780U, 1700U, 1800U, 1960U, 2100U, 2260U, 2440U, 2640U,
    2860U, 3080U, 3320U, 3580U, 3840U, 4120U, 1800U, 1920U, 2100U, 2260U, 2440U,
    2640U, 2860U, 3100U, 3340U, 3600U, 3880U, 4160U, 4460U, 1900U, 2040U, 2240U,
    2420U, 2620U, 2840U, 3080U, 3340U, 3600U, 3880U, 4180U, 4480U, 4800U, 2000U,
    2160U, 2380U, 2580U, 2800U, 3040U, 3300U, 3580U, 3860U, 4160U, 4480U, 4800U,
    5140U, 2100U, 2280U, 2520U, 2740U, 2980U, 3240U, 3520U, 3820U, 4120U, 4440U,
    4780U, 5120U, 5480U, 2200U, 2400U, 2660U, 2900U, 3160U, 3440U, 3740U, 4060U,
    4380U, 4720U, 5080U, 5440U, 5820U, 2300U, 2520U, 2800U, 3060U, 3340U, 3640U,
    3960U, 4300U, 4640U, 5000U, 5380U, 5760U, 6160U, 2400U, 2640U, 2940U, 3220U,
    3520U, 3840U, 4180U, 4540U, 4900U, 5280U, 5680U, 6080U, 6500U, 2500U, 2760U,
    3080U, 3380U, 3700U, 4040U, 4400U, 4780U, 5160U, 5560U, 5980U, 6400U, 6840U
  },

  /* Computed Parameter: Normaldowshift_tableData
   * Referenced by: '<S7>/Normal dowshift'
   */
  { 1000U, 1040U, 1100U, 1180U, 1260U, 1360U, 1480U, 1600U, 1740U, 1880U, 2040U,
    2200U, 2380U, 1040U, 1080U, 1160U, 1240U, 1340U, 1440U, 1560U, 1680U, 1840U,
    2000U, 2180U, 2360U, 2560U, 1100U, 1140U, 1240U, 1340U, 1440U, 1560U, 1680U,
    1820U, 1980U, 2160U, 2360U, 2540U, 2760U, 1180U, 1220U, 1320U, 1440U, 1560U,
    1680U, 1820U, 1960U, 2120U, 2320U, 2540U, 2720U, 2960U, 1260U, 1300U, 1400U,
    1540U, 1680U, 1800U, 1960U, 2100U, 2260U, 2480U, 2720U, 2900U, 3160U, 1340U,
    1380U, 1480U, 1640U, 1800U, 1920U, 2100U, 2240U, 2400U, 2640U, 2900U, 3080U,
    3360U, 1420U, 1460U, 1560U, 1740U, 1920U, 2040U, 2240U, 2380U, 2540U, 2800U,
    3080U, 3260U, 3560U, 1500U, 1540U, 1640U, 1840U, 2040U, 2160U, 2380U, 2520U,
    2680U, 2960U, 3260U, 3440U, 3760U, 1580U, 1620U, 1720U, 1940U, 2160U, 2280U,
    2520U, 2660U, 2820U, 3120U, 3440U, 3620U, 3960U, 1660U, 1700U, 1800U, 2040U,
    2280U, 2400U, 2660U, 2800U, 2960U, 3280U, 3620U, 3800U, 4160U, 1740U, 1780U,
    1880U, 2140U, 2400U, 2520U, 2800U, 2940U, 3100U, 3440U, 3800U, 3980U, 4360U
  },

  /* Computed Parameter: SportModeUpshift_tableData
   * Referenced by: '<S8>/Sport Mode Upshift'
   */
  { 1700U, 1850U, 2000U, 2150U, 2300U, 2450U, 2600U, 2750U, 2900U, 3050U, 3200U,
    3350U, 3500U, 1850U, 2000U, 2150U, 2300U, 2450U, 2600U, 2750U, 2900U, 3050U,
    3200U, 3350U, 3500U, 3650U, 2000U, 2150U, 2300U, 2450U, 2600U, 2750U, 2900U,
    3050U, 3200U, 3350U, 3500U, 3650U, 3800U, 2150U, 2300U, 2450U, 2600U, 2750U,
    2900U, 3050U, 3200U, 3350U, 3500U, 3650U, 3800U, 3950U, 2300U, 2450U, 2600U,
    2750U, 2900U, 3050U, 3200U, 3350U, 3500U, 3700U, 3850U, 4000U, 4200U, 2450U,
    2600U, 2750U, 2900U, 3050U, 3200U, 3400U, 3600U, 3750U, 3950U, 4100U, 4300U,
    4500U, 2600U, 2750U, 2900U, 3050U, 3200U, 3400U, 3600U, 3850U, 4050U, 4250U,
    4400U, 4600U, 4850U, 2750U, 2900U, 3050U, 3200U, 3350U, 3600U, 3800U, 4050U,
    4300U, 4550U, 4700U, 4950U, 5200U, 2900U, 3050U, 3200U, 3350U, 3500U, 3800U,
    4000U, 4250U, 4550U, 4850U, 5000U, 5250U, 5550U, 3050U, 3200U, 3350U, 3500U,
    3650U, 4000U, 4200U, 4450U, 4800U, 5100U, 5300U, 5550U, 5850U, 3200U, 3350U,
    3500U, 3650U, 3800U, 4200U, 4400U, 4650U, 5000U, 5350U, 5600U, 5850U, 6150U
  },

  /* Computed Parameter: SportModeDownshift_tableData
   * Referenced by: '<S8>/Sport Mode Downshift'
   */
  { 900U, 950U, 1000U, 1150U, 1300U, 1450U, 1600U, 1750U, 1900U, 2050U, 2200U,
    2350U, 2500U, 950U, 1000U, 1150U, 1300U, 1450U, 1600U, 1750U, 1900U, 2050U,
    2200U, 2350U, 2500U, 2650U, 1000U, 1150U, 1300U, 1450U, 1600U, 1750U, 1900U,
    2050U, 2200U, 2350U, 2500U, 2650U, 2800U, 1150U, 1300U, 1450U, 1600U, 1750U,
    1900U, 2050U, 2200U, 2350U, 2500U, 2650U, 2800U, 2950U, 1300U, 1450U, 1600U,
    1750U, 1900U, 2050U, 2200U, 2350U, 2500U, 2700U, 2850U, 3000U, 3150U, 1450U,
    1600U, 1750U, 1900U, 2050U, 2200U, 2400U, 2600U, 2750U, 2950U, 3100U, 3300U,
    3450U, 1600U, 1750U, 1900U, 2050U, 2200U, 2400U, 2600U, 2850U, 3050U, 3250U,
    3400U, 3600U, 3750U, 1750U, 1900U, 2050U, 2200U, 2350U, 2600U, 2800U, 3050U,
    3300U, 3550U, 3700U, 3950U, 4100U, 1900U, 2050U, 2200U, 2350U, 2500U, 2800U,
    3000U, 3250U, 3550U, 3850U, 4000U, 4250U, 4400U, 2050U, 2200U, 2350U, 2500U,
    2650U, 3000U, 3200U, 3450U, 3800U, 4100U, 4250U, 4550U, 4700U, 2200U, 2350U,
    2500U, 2650U, 2800U, 3200U, 3400U, 3650U, 4000U, 4350U, 4500U, 4850U, 5000U
  },

  /* Computed Parameter: uDLookupTable2_tableData
   * Referenced by: '<S10>/2-D Lookup Table2'
   */
  { 1U, 5U, 8U, 12U, 16U, 20U, 25U, 30U, 35U, 40U, 5U, 8U, 12U, 16U, 20U, 25U,
    30U, 35U, 40U, 45U, 8U, 12U, 16U, 20U, 25U, 30U, 35U, 40U, 45U, 50U, 12U,
    16U, 20U, 25U, 30U, 35U, 40U, 45U, 50U, 55U, 16U, 20U, 25U, 30U, 35U, 40U,
    45U, 50U, 55U, 60U, 20U, 25U, 30U, 35U, 40U, 45U, 50U, 55U, 60U, 65U, 25U,
    30U, 35U, 40U, 45U, 50U, 55U, 60U, 65U, 70U, 30U, 35U, 40U, 45U, 50U, 55U,
    60U, 65U, 70U, 75U, 35U, 40U, 45U, 50U, 55U, 60U, 65U, 70U, 75U, 80U, 40U,
    45U, 50U, 55U, 60U, 65U, 70U, 75U, 80U, 95U },

  /* Pooled Parameter (Expression: [0 1 2 3 4 5 6 7 8 9]
     )
   * Referenced by: '<S10>/2-D Lookup Table2'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U },

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
  { 0U, 20U, 40U, 60U, 80U, 100U, 120U, 140U, 160U, 180U, 200U, 220U, 240U },

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
  { 0U, 10U, 20U, 30U, 40U, 50U, 60U, 70U, 80U, 90U, 100U },

  /* Computed Parameter: uDLookupTable_bp01Data
   * Referenced by: '<S10>/2-D Lookup Table'
   */
  { 49U, 50U, 51U, 52U, 53U, 54U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
