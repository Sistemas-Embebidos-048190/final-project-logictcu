#ifndef _IOHWAB_ADC_H_
#define _IOHWAB_ADC_H_

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_lpadc.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"
#include "clock_config.h"
#include "fsl_vref.h"
#include "fsl_spc.h"

#define ADC_TEMPERATURE_PIN 	(22)
#define ADC_OUTPUT_SPEED_PIN 	(14)
#define ADC_TRUBINE_SPEED_PIN	(10U)

void Init_ADC_Pins(void);
void TCM_Read_OutputSpeedSensorRaw(void);
void TCM_Read_FluidTempSensorRaw(void);
void TCM_Read_TurbineSpeedSensorRaw(void);

#endif /* _IOHWAB_ADC_H_ */
