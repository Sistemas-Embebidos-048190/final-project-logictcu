/*
 *
 *
 */

#include "IoHwAb_pwm.h"
#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_pwm.h"




static const port_pin_config_t s_pwmPinConfig = {
    /* Internal pull-up/down resistor is disabled */
    kPORT_PullDisable,
    /* Low internal pull resistor value is selected (not used since pull disabled) */
    kPORT_LowPullResistor,
    /* Fast slew rate is configured */
    kPORT_FastSlewRate,
    /* Passive input filter is disabled */
    kPORT_PassiveFilterDisable,
    /* Open drain output is disabled */
    kPORT_OpenDrainDisable,
    /* Low drive strength is configured */
    kPORT_LowDriveStrength,
    /* Pin is configured as GPIO */
	kPORT_MuxAlt5,
    /* Digital input enabled */
    kPORT_InputBufferDisable,
    /* Digital input is not inverted */
    kPORT_InputNormal,
    /* Pin Control Register fields [15:0] are not locked */
    kPORT_UnlockRegister
};

static void PWM_DRV_Init3PhPwm(void)
{
    uint16_t deadTimeVal;
    pwm_signal_param_t pwmSignal[2];
    uint32_t pwmSourceClockInHz;
    uint32_t pwmFrequencyInHz = APP_DEFAULT_PWM_FREQUENCY;

    pwmSourceClockInHz = PWM_SRC_CLK_FREQ;

    /* Set deadtime count, we set this to about 650ns */
    deadTimeVal = ((uint64_t)pwmSourceClockInHz * 650) / 1000000000;

    pwmSignal[0].pwmChannel       = kPWM_PwmA;
    pwmSignal[0].level            = kPWM_HighTrue;
    pwmSignal[0].dutyCyclePercent = 80; /* 1 percent dutycycle */
    pwmSignal[0].deadtimeValue    = deadTimeVal;
    pwmSignal[0].faultState       = kPWM_PwmFaultState0;
    pwmSignal[0].pwmchannelenable = true;

    pwmSignal[1].pwmChannel = kPWM_PwmB;
    pwmSignal[1].level      = kPWM_HighTrue;
    /* Dutycycle field of PWM B does not matter as we are running in PWM A complementary mode */
    pwmSignal[1].dutyCyclePercent = 80;
    pwmSignal[1].deadtimeValue    = deadTimeVal;
    pwmSignal[1].faultState       = kPWM_PwmFaultState0;
    pwmSignal[1].pwmchannelenable = true;

    /*********** PWMA_SM0 - phase A, configuration, setup 2 channel as an example ************/
    PWM_SetupPwm(BOARD_PWM_BASEADDR, kPWM_Module_0, pwmSignal, 2, kPWM_SignedCenterAligned, pwmFrequencyInHz,
                 pwmSourceClockInHz);

    PWM_SetupPwm(BOARD_PWM_BASEADDR, kPWM_Module_1, pwmSignal, 1, kPWM_SignedCenterAligned, pwmFrequencyInHz,
                 pwmSourceClockInHz);

    PWM_SetupPwm(BOARD_PWM_BASEADDR, kPWM_Module_2, pwmSignal, 1, kPWM_SignedCenterAligned, pwmFrequencyInHz,
                 pwmSourceClockInHz);
}

void Init_Pin_PWM(void)
{
	PORT_SetPinConfig(PORT2, LINE_PRESSURE_PIN, &s_pwmPinConfig);
	PORT_SetPinConfig(PORT2, TCC_CONTROL_PIN, &s_pwmPinConfig);

    /* Structure of initialize PWM */
    pwm_config_t pwmConfig;
    pwm_fault_param_t faultConfig;
    uint32_t pwmVal = 4;

    PWM_GetDefaultConfig(&pwmConfig);

    /* Use full cycle reload */
    pwmConfig.reloadLogic = kPWM_ReloadPwmFullCycle;
    /* PWM A & PWM B form a complementary PWM pair */
    pwmConfig.pairOperation   = kPWM_Independent;
    pwmConfig.enableDebugMode = true;

	/* Initialize submodule 0 */
    if (PWM_Init(BOARD_PWM_BASEADDR, kPWM_Module_0, &pwmConfig) == kStatus_Fail)
    {
    	PRINTF("PWM initialization failed\n");

    }

    /* Initialize submodule 1, make it use same counter clock as submodule 0. */
    pwmConfig.clockSource           = kPWM_Submodule0Clock;
    pwmConfig.prescale              = kPWM_Prescale_Divide_1;
    pwmConfig.initializationControl = kPWM_Initialize_MasterSync;
    if (PWM_Init(BOARD_PWM_BASEADDR, kPWM_Module_1, &pwmConfig) == kStatus_Fail)
    {
    	PRINTF("PWM initialization failed\n");
    }

    /* Initialize submodule 2 the same way as submodule 1 */
    if (PWM_Init(BOARD_PWM_BASEADDR, kPWM_Module_2, &pwmConfig) == kStatus_Fail)
    {
	   PRINTF("PWM initialization failed\n");
    }

    /*
     *   config->faultClearingMode = kPWM_Automatic;
     *   config->faultLevel = false;
     *   config->enableCombinationalPath = true;
     *   config->recoverMode = kPWM_NoRecovery;
     */
    PWM_FaultDefaultConfig(&faultConfig);


    faultConfig.faultLevel = DEMO_PWM_FAULT_LEVEL;

    /* Sets up the PWM fault protection */
    PWM_SetupFaults(BOARD_PWM_BASEADDR, kPWM_Fault_0, &faultConfig);
    PWM_SetupFaults(BOARD_PWM_BASEADDR, kPWM_Fault_1, &faultConfig);
    PWM_SetupFaults(BOARD_PWM_BASEADDR, kPWM_Fault_2, &faultConfig);
    PWM_SetupFaults(BOARD_PWM_BASEADDR, kPWM_Fault_3, &faultConfig);

    /* Set PWM fault disable mapping for submodule 0/1/2 */
    PWM_SetupFaultDisableMap(BOARD_PWM_BASEADDR, kPWM_Module_0, kPWM_PwmA, kPWM_faultchannel_0,
							DEMO_PWM_DISABLE_MAP_OP(kPWM_FaultDisable_0 | kPWM_FaultDisable_1 | kPWM_FaultDisable_2 | kPWM_FaultDisable_3));
    PWM_SetupFaultDisableMap(BOARD_PWM_BASEADDR, kPWM_Module_1, kPWM_PwmA, kPWM_faultchannel_0,
							DEMO_PWM_DISABLE_MAP_OP(kPWM_FaultDisable_0 | kPWM_FaultDisable_1 | kPWM_FaultDisable_2 | kPWM_FaultDisable_3));
    PWM_SetupFaultDisableMap(BOARD_PWM_BASEADDR, kPWM_Module_2, kPWM_PwmA, kPWM_faultchannel_0,
							DEMO_PWM_DISABLE_MAP_OP(kPWM_FaultDisable_0 | kPWM_FaultDisable_1 | kPWM_FaultDisable_2 | kPWM_FaultDisable_3));
    /*
     * Call the init function with demo configuration.
     * Recommend to invoke API PWM_SetupPwm after PWM and fault configuration, because reference manual advises to
     * set OUTEN register after other PWM configurations. But set OUTEN register before MCTRL register is okay.
     */
    PWM_DRV_Init3PhPwm();

    /* Set the load okay bit for all submodules to load registers from their buffer */
    PWM_SetPwmLdok(BOARD_PWM_BASEADDR, kPWM_Control_Module_0 | kPWM_Control_Module_1 | kPWM_Control_Module_2, true);

    /* Start the PWM generation from Submodules 0, 1 and 2 */
    PWM_StartTimer(BOARD_PWM_BASEADDR, kPWM_Control_Module_0 | kPWM_Control_Module_1 | kPWM_Control_Module_2);
}
