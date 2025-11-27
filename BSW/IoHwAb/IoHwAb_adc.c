/*
 *
 */

#include "IoHwAb_adc.h"

#define TCM_LPADC0_BASE  	ADC0
#define TCM_LPADC1_BASE		ADC1
#define DEMO_VREF_BASE 		VREF0

// IDs de comandos LPADC (1–15 válidos)
#define TCM_LPADC_CMDID_OUTPUT      1U   // P0_14  Output_Speed_Sensor
#define TCM_LPADC_CMDID_FLUID       2U   // P0_22  Fluid_Trans_Temperature
#define TCM_LPADC_CMDID_TURBINE     3U   // P1_10  Turbine_Speed_Sensor

// Triggers de software (0–3 típicamente)
#define TCM_LPADC_TRIG_OUTPUT       0U
#define TCM_LPADC_TRIG_FLUID        1U
#define TCM_LPADC_TRIG_TURBINE      2U

#define TCM_LPADC_RESULT_MASK   (0xFFFFU)
#define TCM_LPADC_RESULTSHIFT   (0U)

#define DEMO_LPADC_VREF_SOURCE           kLPADC_ReferenceVoltageAlt3
#define DEMO_LPADC_DO_OFFSET_CALIBRATION true
#define DEMO_LPADC_OFFSET_VALUE_A        0x10U
#define DEMO_LPADC_OFFSET_VALUE_B        0x10U

#define DEMO_SPC_BASE           SPC0

static const port_pin_config_t adc_PinConfig = {
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
	kPORT_MuxAlt0,
    /* Digital input enabled */
    kPORT_InputBufferDisable,
    /* Digital input is not inverted */
    kPORT_InputNormal,
    /* Pin Control Register fields [15:0] are not locked */
    kPORT_UnlockRegister
};

void Init_ADC_Pins(void)
{

    PORT_SetPinConfig(PORT0, ADC_TEMPERATURE_PIN, &adc_PinConfig);
    PORT_SetPinConfig(PORT0, ADC_OUTPUT_SPEED_PIN, &adc_PinConfig);
    PORT_SetPinConfig(PORT1, ADC_TRUBINE_SPEED_PIN, &adc_PinConfig);

    vref_config_t vrefConfig;

    /* 1) Configurar el reloj funcional de ADC0 */
    CLOCK_SetClkDiv(kCLOCK_DivAdc0Clk, 1U);
    CLOCK_AttachClk(kFRO_HF_to_ADC0);

    /* 1) Configurar el reloj funcional de ADC1 */
    CLOCK_SetClkDiv(kCLOCK_DivAdc1Clk, 1U);
    CLOCK_AttachClk(kFRO_HF_to_ADC1);

    /* enable VREF */
    SPC_EnableActiveModeAnalogModules(DEMO_SPC_BASE, kSPC_controlVref);

    VREF_GetDefaultConfig(&vrefConfig);
    vrefConfig.bufferMode = kVREF_ModeBandgapOnly;
    /* Initialize VREF module, the VREF module is only used to supply the bias current for LPADC. */
    VREF_Init(DEMO_VREF_BASE, &vrefConfig);

    lpadc_config_t              lpadcConfig;
    lpadc_conv_command_config_t cmdConfig;
    lpadc_conv_trigger_config_t trigConfig;

    /* Config básica del LPADC */
    LPADC_GetDefaultConfig(&lpadcConfig);
    lpadcConfig.powerLevelMode = kLPADC_PowerLevelAlt4;
	lpadcConfig.enableAnalogPreliminary = true;
	lpadcConfig.referenceVoltageSource = 2U;

	lpadcConfig.conversionAverageMode = kLPADC_ConversionAverage128;

	LPADC_Init(TCM_LPADC0_BASE, &lpadcConfig);
	LPADC_DoOffsetCalibration(TCM_LPADC0_BASE); /* Request offset calibration, automatic update OFSTRIM register. */
	LPADC_DoAutoCalibration(TCM_LPADC0_BASE);

	LPADC_Init(TCM_LPADC1_BASE, &lpadcConfig);
	LPADC_DoOffsetCalibration(TCM_LPADC1_BASE); /* Request offset calibration, automatic update OFSTRIM register. */
	LPADC_DoAutoCalibration(TCM_LPADC1_BASE);

    /* OUTPUT_SPEED_SENSOR  (P0_14 = ADC0_B14 → canal 14, lado B) */
    cmdConfig.channelNumber     = 14U;
    cmdConfig.sampleChannelMode = kLPADC_SampleChannelSingleEndSideB;
    LPADC_SetConvCommandConfig(TCM_LPADC0_BASE, TCM_LPADC_CMDID_OUTPUT, &cmdConfig);

    /* ADC_TEMPERATURE_PIN  (P0_22 = ADC0_A14 → canal 14, lado A) */
    cmdConfig.channelNumber     = 14U;
    cmdConfig.sampleChannelMode = kLPADC_SampleChannelSingleEndSideA;
    LPADC_SetConvCommandConfig(TCM_LPADC0_BASE, TCM_LPADC_CMDID_FLUID, &cmdConfig);

    /* ADC_TRUBINE_SPEED_PIN  (P1_10 = ADC1_A10 → canal 10, lado A) */
    cmdConfig.channelNumber     = 10U;
    cmdConfig.sampleChannelMode = kLPADC_SampleChannelSingleEndSideA;
    LPADC_SetConvCommandConfig(TCM_LPADC1_BASE, TCM_LPADC_CMDID_TURBINE, &cmdConfig);

    /* Triggers de software para cada comando */
    LPADC_GetDefaultConvTriggerConfig(&trigConfig);
    trigConfig.targetCommandId = TCM_LPADC_CMDID_OUTPUT;
    trigConfig.enableHardwareTrigger = false;  // puro software trigger

//    /* Triggers de software para cada comando */
//    LPADC_GetDefaultConvTriggerConfig(&trigConfig);
//    trigConfig.targetCommandId = TCM_LPADC_CMDID_FLUID;
//    trigConfig.enableHardwareTrigger = false;  // puro software trigger
//
//    /* Triggers de software para cada comando */
//    LPADC_GetDefaultConvTriggerConfig(&trigConfig);
//    trigConfig.targetCommandId = TCM_LPADC_CMDID_TURBINE;
//    trigConfig.enableHardwareTrigger = false;  // puro software trigger

    //trigConfig.targetCommandId = TCM_LPADC_CMDID_OUTPUT;
    LPADC_SetConvTriggerConfig(TCM_LPADC0_BASE, TCM_LPADC_TRIG_OUTPUT, &trigConfig);
//    LPADC_SetConvTriggerConfig(TCM_LPADC0_BASE, TCM_LPADC_TRIG_FLUID, &trigConfig);
//    LPADC_SetConvTriggerConfig(TCM_LPADC1_BASE, TCM_LPADC_TRIG_TURBINE, &trigConfig);

    lpadc_conv_result_t mLpadcResultConfigStruct;
}


void TCM_Read_OutputSpeedSensorRaw(void)
{
//	lpadc_conv_result_t result;
//	uint32_t triggerMask = (1UL << 0);
//	const uint32_t g_LpadcResultShift = 3U;
//
//	LPADC_DoSoftwareTrigger(TCM_LPADC_BASE, triggerMask);
//
//	while (!LPADC_GetConvResult(TCM_LPADC_BASE, &result, 0U))
//	{
//	}
//	Write_TCM_OutputSpeed_OSS( (result.convValue) >> g_LpadcResultShift  );
}


void TCM_Read_FluidTempSensorRaw(void)
{
//	Write_TCM_FluidTemp_TFT( TCM_LPADC_ReadByTrigger(TCM_LPADC_TRIG_FLUID) );
}

void TCM_Read_TurbineSpeedSensorRaw(void)
{
//	Write_TCM_TurbineSpeed_TSS (TCM_LPADC_ReadByTrigger(TCM_LPADC_TRIG_TURBINE) );
}
