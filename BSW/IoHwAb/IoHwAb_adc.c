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
 * @brief Configures pin mux for all ADC input pins.
 *
 * Pins:
 *  - ADC_OUTPUT_SPEED_PIN   : output speed sensor
 *  - ADC_TEMPERATURE_PIN    : transmission fluid temperature
 *  - ADC_TURBINE_SPEED_PIN  : turbine speed sensor
 *
 * This function only handles the PORT mux; LPADC/VREF/clock are initialized
 * in @ref TCM_LPADC_InitSensors.
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

/**
 * @brief Initializes LPADC, VREF, clocks and conversion commands/triggers.
 *
 * Steps:
 *  1) Configure functional clock for ADC (TCM_LPADC_BASE).
 *  2) Enable and configure VREF (bias current for LPADC).
 *  3) Configure LPADC common settings and perform calibration.
 *  4) Configure conversion commands for each sensor:
 *     - TCM_LPADC_CMDID_OUTPUT  → TCM_LPADC_CHANNEL_OUTPUT
 *     - TCM_LPADC_CMDID_FLUID   → TCM_LPADC_CHANNEL_FLUID
 *     - TCM_LPADC_CMDID_TURBINE → TCM_LPADC_CHANNEL_TURBINE
 *  5) Configure software triggers for each command:
 *     - TCM_LPADC_TRIG_OUTPUT / FLUID / TURBINE
 */
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

/**
 * @brief Reads Output Speed Sensor, converts ADC to RPM, and writes to RTE.
 *
 * Conversión usada:
 *  1) Se obtiene un valor ADC efectivo de 12 bits:
 *       counts = (convValue >> 3)   → [0 .. 4095]
 *  2) Se mapea linealmente a 0 .. 8000 RPM:
 *       rpm = counts / 4095 * 8000
 */
void TCM_Read_OutputSpeedSensorRaw(void)
{
	lpadc_conv_result_t result;
	uint32 triggerMask = (1UL << TCM_LPADC_TRIG_OUTPUT);
	const uint32_t g_LpadcResultShift = TCM_LPADC_RESULT_SHIFT;

	LPADC_DoSoftwareTrigger(TCM_LPADC_BASE, triggerMask);

	while (!LPADC_GetConvResult(TCM_LPADC_BASE, &result, 0U))
	{
	}

	/* Escalado a RPM sin overflow:
     * rpm = counts / 4095 * 8000
     */
	uint32 temp = (uint32)((result.convValue) >> g_LpadcResultShift) * OSS_ADC_MAX_RPM;   // evitar overflow
	uint16 rpm  = (uint16)(temp / OSS_ADC_MAX_COUNTS);

	Rte_write_g_HW_OutputSpeed( rpm );

}

/**
 * @brief Reads Transmission Fluid Temperature, converts ADC to °C, and writes to RTE.
 *
 * Conversión usada (lineal):
 *  1) counts = (convValue >> 3)           → [0 .. 4095]
 *  2) temp_span = counts / 4095 * 190     → [0 .. 190]
 *  3) temp_C = temp_span + (-40)          → [-40 .. 150]
 */
void TCM_Read_FluidTempSensorRaw(void)
{
	lpadc_conv_result_t result;
	uint32 triggerMask = (1UL << TCM_LPADC_TRIG_FLUID);
	const uint32_t g_LpadcResultShift = TCM_LPADC_RESULT_SHIFT;

	LPADC_DoSoftwareTrigger(TCM_LPADC_BASE, triggerMask);

	while (!LPADC_GetConvResult(TCM_LPADC_BASE, &result, 0U))
	{
	}

	sint32 temp = (sint32)((result.convValue) >> g_LpadcResultShift) * TFT_SPAN_TEMP;  // span = 190 °C
	temp /= TFT_ADC_MAX_COUNTS;                        	// ahora está en [0, 190]
	temp += TFT_MIN_TEMP;                         		// desplazar a [-40, 150]

	Rte_write_g_HW_TransmissionTEMP( temp );
}

/**
 * @brief Reads Turbine Speed Sensor, converts ADC to RPM, and writes to RTE.
 *
 * Conversión usada (misma que Output Speed):
 *  1) counts = (convValue >> 3)           → [0 .. 4095]
 *  2) rpm    = counts / 4095 * 8000      → [0 .. 8000]
 */
void TCM_Read_TurbineSpeedSensorRaw(void)
{
		lpadc_conv_result_t result;
		uint32 triggerMask = (1UL << TCM_LPADC_TRIG_TURBINE);
		const uint32_t g_LpadcResultShift = TCM_LPADC_RESULT_SHIFT;

		LPADC_DoSoftwareTrigger(TCM_LPADC_BASE, triggerMask);

		while (!LPADC_GetConvResult(TCM_LPADC_BASE, &result, 0U))
		{
		}

		uint32 temp = (uint32)((result.convValue) >> g_LpadcResultShift) * TSS_MAX_RPM;   // evitar overflow
		uint16 rpm  = (uint16)(temp / TSS_ADC_MAX_COUNTS);

		Rte_write_g_HW_TurbineSpeed(rpm);
}
