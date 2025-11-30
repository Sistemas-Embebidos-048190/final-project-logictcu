/*
 * @file    IoHwAb_adc.c
 * @brief   LPADC initialization and raw acquisition for TCM sensors.
 *
 * This module belongs to the IoHwAb (I/O Hardware Abstraction) layer and is
 * responsible for configuring and using the LPADC instances to read:
 *  - Output speed sensor
 *  - Transmission fluid temperature sensor
 *  - Turbine speed sensor
 *
 * It configures:
 *  - Pin mux for ADC channels
 *  - Clocks for ADC0 / ADC1
 *  - VREF module
 *  - LPADC common configuration
 *  - Conversion commands and software triggers for each signal
 */

/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "IoHwAb_adc.h"

/* **********************************************************************
 * Definitions
 * *********************************************************************/
#define TCM_LPADC_RESULT_MASK   (0xFFFFU)
#define TCM_LPADC_RESULTSHIFT   (0U)

#define DEMO_LPADC_VREF_SOURCE           kLPADC_ReferenceVoltageAlt3
#define DEMO_LPADC_DO_OFFSET_CALIBRATION true
#define DEMO_LPADC_OFFSET_VALUE_A        0x10U
#define DEMO_LPADC_OFFSET_VALUE_B        0x10U

/* **********************************************************************
 * Static pin configuration
 * *********************************************************************/

/**
 * @brief Common PORT configuration for ADC input pins.
 *
 *  - No pull-up/down
 *  - Fast slew rate
 *  - No passive filter
 *  - Push-pull (open drain disabled)
 *  - Low drive strength
 *  - Pin muxed as ALT0 (ADC function)
 *  - Input buffer disabled (handled by analog block)
 */
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

/* **********************************************************************
 * Global functions
 * *********************************************************************/

/**
 * @brief Initializes ADC pins, clocks, VREF and LPADC commands/triggers.
 *
 * Configures:
 *  - Pins:
 *      - ADC_OUTPUT_SPEED_PIN   (Output speed sensor)
 *      - ADC_TEMPERATURE_PIN    (Fluid temperature sensor)
 *      - ADC_TRUBINE_SPEED_PIN  (Turbine speed sensor)
 *  - Clocks for ADC0 and ADC1
 *  - VREF module (bias for LPADC)
 *  - LPADC0 and LPADC1 common configuration and calibration
 *  - Conversion commands and software triggers for each sensor
 */
void Init_ADC_Pins(void)
{
    /* ------------------------------------------------------------------
     * Configure pin mux for ADC inputs
     * ------------------------------------------------------------------ */
	PORT_SetPinConfig(PORT0, ADC_OUTPUT_SPEED_PIN, &adc_PinConfig);
	PORT_SetPinConfig(PORT0, ADC_TEMPERATURE_PIN, &adc_PinConfig);
    PORT_SetPinConfig(PORT0, ADC_TURBINE_SPEED_PIN, &adc_PinConfig);
}

void TCM_LPADC_InitSensors(void)
{
	vref_config_t vrefConfig;
	/* ------------------------------------------------------------------
	 *  Configure functional clocks for ADC0
	 * ------------------------------------------------------------------ */
	CLOCK_SetClkDiv(kCLOCK_DivAdc0Clk, TCM_LPADC_CLOCK_DIVIDER);
	CLOCK_AttachClk(kFRO_HF_to_ADC0);

	/* ------------------------------------------------------------------
	 * Enable and configure VREF (bias for LPADC)
	 * ------------------------------------------------------------------ */
	SPC_EnableActiveModeAnalogModules(DEMO_SPC_BASE, kSPC_controlVref);
	VREF_GetDefaultConfig(&vrefConfig);
	vrefConfig.bufferMode = kVREF_ModeBandgapOnly;
	/* Initialize VREF module, the VREF module is only used to supply the bias current for LPADC. */
	VREF_Init(DEMO_VREF_BASE, &vrefConfig);

	/* ------------------------------------------------------------------
	 * Configure LPADC common settings and calibrate
	 * ------------------------------------------------------------------ */
	lpadc_config_t              lpadcConfig;
	lpadc_conv_command_config_t cmdConfig;
	lpadc_conv_trigger_config_t trigConfig;

	LPADC_GetDefaultConfig(&lpadcConfig);
	lpadcConfig.powerLevelMode = kLPADC_PowerLevelAlt4;
	lpadcConfig.enableAnalogPreliminary = true;
	lpadcConfig.referenceVoltageSource = 2U;

	lpadcConfig.conversionAverageMode = kLPADC_ConversionAverage128;

	/* Initialize and calibrate ADC0 */
	LPADC_Init(TCM_LPADC_BASE, &lpadcConfig);
	LPADC_DoOffsetCalibration(TCM_LPADC_BASE); /* Request offset calibration, automatic update OFSTRIM register. */
	LPADC_DoAutoCalibration(TCM_LPADC_BASE);


	/* ------------------------------------------------------------------
	 * 5) Configure conversion commands for each sensor
	 * ------------------------------------------------------------------ */
	LPADC_GetDefaultConvCommandConfig(&cmdConfig);

	/* OUTPUT_SPEED_SENSOR  (P0_14 = ADC0_B14 → canal 14, lado B) */
	cmdConfig.channelNumber     = TCM_LPADC_CHANNEL_OUTPUT;
	cmdConfig.sampleChannelMode = kLPADC_SampleChannelSingleEndSideB;
	LPADC_SetConvCommandConfig(TCM_LPADC_BASE, TCM_LPADC_CMDID_OUTPUT, &cmdConfig);

	/* ADC_TEMPERATURE_PIN  (P0_22 = ADC0_A14 → canal 14, lado A) */
	cmdConfig.channelNumber     = TCM_LPADC_CHANNEL_FLUID;
	cmdConfig.sampleChannelMode = kLPADC_SampleChannelSingleEndSideA;
	LPADC_SetConvCommandConfig(TCM_LPADC_BASE, TCM_LPADC_CMDID_FLUID, &cmdConfig);

	/* ADC_TRUBINE_SPEED_PIN  (P0_15 = ADC0_B15 → canal 15, lado B) */
	cmdConfig.channelNumber     = TCM_LPADC_CHANNEL_TURBINE;
	cmdConfig.sampleChannelMode = kLPADC_SampleChannelSingleEndSideB;
	LPADC_SetConvCommandConfig(TCM_LPADC_BASE, TCM_LPADC_CMDID_TURBINE, &cmdConfig);

	/* ------------------------------------------------------------------
	 * Configure software triggers for each command
	 * ------------------------------------------------------------------ */
	/* OUTPUT and FLUID: software triggers on LPADC0 */
	LPADC_GetDefaultConvTriggerConfig(&trigConfig);
	trigConfig.targetCommandId = TCM_LPADC_CMDID_OUTPUT;
	trigConfig.enableHardwareTrigger = false;  // puro software trigger


    trigConfig.targetCommandId = TCM_LPADC_CMDID_OUTPUT;
    LPADC_SetConvTriggerConfig(TCM_LPADC_BASE, TCM_LPADC_TRIG_OUTPUT, &trigConfig);

    trigConfig.targetCommandId = TCM_LPADC_CMDID_FLUID;
    LPADC_SetConvTriggerConfig(TCM_LPADC_BASE, TCM_LPADC_TRIG_FLUID, &trigConfig);

    trigConfig.targetCommandId = TCM_LPADC_CMDID_TURBINE;
    LPADC_SetConvTriggerConfig(TCM_LPADC_BASE, TCM_LPADC_TRIG_TURBINE, &trigConfig);
}


void TCM_Read_OutputSpeedSensorRaw(void)
{
	lpadc_conv_result_t result;
	uint32 triggerMask = (1UL << TCM_LPADC_TRIG_OUTPUT);
	const uint32_t g_LpadcResultShift = 3U;

	LPADC_DoSoftwareTrigger(TCM_LPADC_BASE, triggerMask);

	while (!LPADC_GetConvResult(TCM_LPADC_BASE, &result, 0U))
	{
	}

	uint32 temp = (uint32)((result.convValue) >> g_LpadcResultShift) * 8000U;   // evitar overflow
	uint16 rpm  = (uint16)(temp / 4095U);

	Rte_write_g_HW_OutputSpeed( rpm );

}

void TCM_Read_FluidTempSensorRaw(void)
{
	lpadc_conv_result_t result;
	uint32 triggerMask = (1UL << TCM_LPADC_TRIG_FLUID);
	const uint32_t g_LpadcResultShift = 3U;

	LPADC_DoSoftwareTrigger(TCM_LPADC_BASE, triggerMask);

	while (!LPADC_GetConvResult(TCM_LPADC_BASE, &result, 0U))
	{
	}

	sint32 temp = (sint32)((result.convValue) >> g_LpadcResultShift) * 190;  // span = 190 °C
	temp /= 4095;                        // ahora está en [0, 190]
	temp += -40;                         // desplazar a [-40, 150]

	Rte_write_g_HW_TransmissionTEMP( temp );
}

void TCM_Read_TurbineSpeedSensorRaw(void)
{
		lpadc_conv_result_t result;
		uint32 triggerMask = (1UL << TCM_LPADC_TRIG_TURBINE);
		const uint32_t g_LpadcResultShift = 3U;

		LPADC_DoSoftwareTrigger(TCM_LPADC_BASE, triggerMask);

		while (!LPADC_GetConvResult(TCM_LPADC_BASE, &result, 0U))
		{
		}

		uint32 temp = (uint32)((result.convValue) >> g_LpadcResultShift) * 8000U;   // evitar overflow
		uint16 rpm  = (uint16)(temp / 4095U);

		Rte_write_g_HW_TurbineSpeed(rpm);
}
