#ifndef _IOHWAB_PWM_H_
#define _IOHWAB_PWM_H_

#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"
#include "fsl_pwm.h"


#define LINE_PRESSURE_PIN	(6U)
#define TCC_CONTROL_PIN		(7U)

#define BOARD_PWM_BASEADDR        PWM1
#define PWM_SRC_CLK_FREQ          CLOCK_GetFreq(kCLOCK_BusClk)
#define DEMO_PWM_FAULT_LEVEL      true
#define APP_DEFAULT_PWM_FREQUENCY (10000UL)
#define DEMO_PWM_DISABLE_MAP_OP

static void PWM_DRV_Init3PhPwm(void);
void Init_Pin_PWM(void);


#endif /* _IOHWAB_PWM_H_ */
