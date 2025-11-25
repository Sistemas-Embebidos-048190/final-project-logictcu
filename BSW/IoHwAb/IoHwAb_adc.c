/*
 *
 */

#include "IoHwAb_adc.h"

static const port_pin_config_t s_adcPinConfig = {
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
	kPORT_MuxAlt2,
    /* Digital input enabled */
    kPORT_InputBufferEnable,
    /* Digital input is not inverted */
    kPORT_InputNormal,
    /* Pin Control Register fields [15:0] are not locked */
    kPORT_UnlockRegister
};

void BOARD_InitBootPins_ADC(void)
{
    BOARD_InitADC_Pins();
}

void BOARD_InitADC_Pins(void)
{
    lpadc_config_t mLpadcConfigStruct;
    lpadc_conv_trigger_config_t mLpadcTriggerConfigStruct;
    lpadc_conv_command_config_t mLpadcCommandConfigStruct;
    lpadc_conv_result_t mLpadcResultConfigStruct;

	LPADC_GetDefaultConfig(&mLpadcConfigStruct);
	LPADC_Init(DEMO_LPADC_BASE, &mLpadcConfigStruct);
	LPADC_DoOffsetCalibration(DEMO_LPADC_BASE); /* Request offset calibration, automatic update OFSTRIM register. */
	LPADC_DoAutoCalibration(DEMO_LPADC_BASE);
	LPADC_GetDefaultConvCommandConfig(&mLpadcCommandConfigStruct);
	LPADC_GetDefaultConvTriggerConfig(&mLpadcTriggerConfigStruct);
	LPADC_DoSoftwareTrigger(DEMO_LPADC_BASE, 1U); /* 1U is trigger0 mask. */

    /* PORT1_8 (pin A1) is configured as FC4_P0 */
    PORT_SetPinConfig(PORT0, ADC_TEMPERATURE_PIN, &s_adcPinConfig);

    /* PORT1_9 (pin B1) is configured as FC4_P1 */
    PORT_SetPinConfig(PORT0, ADC_OUTPUT_SPEED_PIN, &s_adcPinConfig);

    /* PORT4_23 (pin U12) is configured as ADC0_A2 */
    PORT_SetPinConfig(PORT0, ADC_TRUBINE_SPEED_PIN, &s_adcPinConfig);
}
