

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_lpadc.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"

#define ADC_TEMPERATURE_PIN 	(22)
#define ADC_OUTPUT_SPEED_PIN 	(14)
#define ADC_TRUBINE_SPEED_PIN	(15)

void BOARD_InitADC_Pins(void);
void BOARD_InitBootPins_ADC(void);
