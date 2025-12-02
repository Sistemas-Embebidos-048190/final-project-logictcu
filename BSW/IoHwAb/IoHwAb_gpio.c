/*
 * @file    IoHwAb_gpio.c
 * @brief   GPIO initialization for Transmission Control Module signals.
 *
 * This module belongs to the IoHwAb (I/O Hardware Abstraction) layer and is
 * responsible for configuring all GPIO pins related to:
 *  - Brake pedal input
 *  - Gear position inputs (P, R, N, D, 1st, 2nd)
 *  - Shift solenoids (A, B, C, D, E)
 *  - Shift-lock solenoid
 *
 * All pin numbers (BREAK_PEDAL_PIN, PARKING_PIN, etc.) are expected to be
 * defined in the corresponding header files (e.g. app.h, IoHwAb_gpio.h)
 * so that there are no hard-coded numerical values in this source file.
 *
 * The initialization functions provided here MUST be called once during
 * system startup before any of the corresponding signals are used.
 */

/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "IoHwAb_gpio.h"

/* **********************************************************************
 * Definitions
 * *********************************************************************/

/**
 * @brief Default logic level used when initializing output pins.
 */
#define GPIO_LOGIC_LEVEL_LOW   (0u)

/**
 * @brief Logic level considered as active/high for inputs.
 */
#define GPIO_LOGIC_LEVEL_HIGH   (1u)

/* **********************************************************************
 * Static configuration structures
 * *********************************************************************/
static const port_pin_config_t s_gpioPinConfig = {
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
    kPORT_MuxAsGpio,
    /* Digital input enabled */
    kPORT_InputBufferEnable,
    /* Digital input is not inverted */
    kPORT_InputNormal,
    /* Pin Control Register fields [15:0] are not locked */
    kPORT_UnlockRegister
};


/* **********************************************************************
 * Functions
 * *********************************************************************/

/**
 * @brief Initializes the GPIO used to read the brake pedal switch.
 *
 * This function:
 *  - Configures the BRAKE_PEDAL pin mux as GPIO.
 *  - Initializes the pin as a digital input.
 *
 * Must be called during system startup before reading the brake pedal state.
 */
void Init_Pin_BreakPedal (void)
{
    /*PIN BREAK PEDAL*/

	/* PORT3_PIN4 is configured as input */
    PORT_SetPinConfig(PORT3, BREAK_PEDAL_PIN, &s_gpioPinConfig);

    gpio_pin_config_t Pin_BreakPedal_config = {
    	kGPIO_DigitalInput,
		GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO3, BREAK_PEDAL_PIN, &Pin_BreakPedal_config);
}

/**
 * @brief Initializes the GPIOs used to read the gear lever position.
 *
 * This function configures the following pins as digital inputs:
 *  - PARKING_PIN : Parking position (P)
 *  - REVERSE_PIN : Reverse position (R)
 *  - NEUTRAL_PIN : Neutral position (N)
 *  - DRIVE_PIN   : Drive position (D)
 *  - FIRST_PIN   : First manual gear (1)
 *  - SECOND_PIN  : Second manual gear (2)
 *
 * All pins are muxed as GPIO and configured as digital inputs.
 */
void Init_Pin_GearPossition(void)
{
    /* --- PORT mux configuration for gear position pins --- */
    PORT_SetPinConfig(PORT1, PARKING_PIN, &s_gpioPinConfig);
    PORT_SetPinConfig(PORT1, REVERSE_PIN, &s_gpioPinConfig);
    PORT_SetPinConfig(PORT3, NEUTRAL_PIN, &s_gpioPinConfig);
    PORT_SetPinConfig(PORT2, DRIVE_PIN, &s_gpioPinConfig);
    PORT_SetPinConfig(PORT1, FIRST_PIN, &s_gpioPinConfig);
    //PORT_SetPinConfig(PORT1, SECOND_PIN, &s_gpioPinConfig);

    /* --- GPIO configuration as digital inputs --- */

    gpio_pin_config_t parkingConfig = {
        kGPIO_DigitalInput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO1, PARKING_PIN, &parkingConfig);

    gpio_pin_config_t reverseConfig = {
        kGPIO_DigitalInput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO1, REVERSE_PIN, &reverseConfig);

    gpio_pin_config_t neutralConfig = {
        kGPIO_DigitalInput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO3, NEUTRAL_PIN, &neutralConfig);

    gpio_pin_config_t driveConfig = {
        kGPIO_DigitalInput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO2, DRIVE_PIN, &driveConfig);

    gpio_pin_config_t firstConfig = {
       kGPIO_DigitalInput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO1, FIRST_PIN, &firstConfig);

//    gpio_pin_config_t secondConfig = {
//        kGPIO_DigitalInput,
//        GPIO_LOGIC_LEVEL_LOW,
//    };
//    GPIO_PinInit(GPIO1, SECOND_PIN, &secondConfig);
}

/**
 * @brief Initializes the GPIOs that drive the shift solenoids.
 *
 * This function configures the following pins as digital outputs:
 *  - SOLENOID_A_PIN
 *  - SOLENOID_B_PIN
 *  - SOLENOID_C_PIN
 *  - SOLENOID_D_PIN
 *  - SOLENOID_E_PIN
 *
 * All pins are muxed as GPIO and initialized as digital outputs with
 * a default LOW logic level (solenoids de-energized).
 */
void Init_Pin_ShiftSolenoids(void)
{
    /* --- PORT mux configuration for solenoid pins --- */
    PORT_SetPinConfig(PORT1, SOLENOID_A_PIN, &s_gpioPinConfig);
    PORT_SetPinConfig(PORT1, SOLENOID_B_PIN, &s_gpioPinConfig);
    PORT_SetPinConfig(PORT1, SOLENOID_C_PIN, &s_gpioPinConfig);
    PORT_SetPinConfig(PORT1, SOLENOID_D_PIN, &s_gpioPinConfig);
    PORT_SetPinConfig(PORT4, SOLENOID_E_PIN, &s_gpioPinConfig);

    /* --- GPIO configuration as digital outputs --- */

    gpio_pin_config_t solenoidAConfig = {
        kGPIO_DigitalOutput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO1, SOLENOID_A_PIN, &solenoidAConfig);

    gpio_pin_config_t solenoidBConfig = {
        kGPIO_DigitalOutput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO1, SOLENOID_B_PIN, &solenoidBConfig);

    gpio_pin_config_t solenoidCConfig = {
        kGPIO_DigitalOutput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO1, SOLENOID_C_PIN, &solenoidCConfig);

    gpio_pin_config_t solenoidDConfig = {
        kGPIO_DigitalOutput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO1, SOLENOID_D_PIN, &solenoidDConfig);

    gpio_pin_config_t solenoidEConfig = {
        kGPIO_DigitalOutput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO4, SOLENOID_E_PIN, &solenoidEConfig);
}

/**
 * @brief Initializes the GPIO that drives the shift-lock solenoid.
 *
 * The shift-lock solenoid prevents the gear lever from being moved out
 * of PARK unless certain conditions are met (e.g. brake pedal pressed).
 *
 * This function:
 *  - Configures the LOCK_SOLENOID pin mux as GPIO.
 *  - Initializes the pin as a digital output with LOW default level
 *    (solenoid de-energized).
 *
 * @note The PORT and GPIO instances (PORT5/GPIO5) and the LOCK_SOLENOID pin
 *       macro must be defined in the board- or application-specific headers.
 */
void Init_Pin_ShiftLockSolenoid(void)
{
    /* Configure PORT muxing for the shift-lock solenoid pin */
    PORT_SetPinConfig(PORT5, LOCK_SOLENOID, &s_gpioPinConfig);

    /* Configure GPIO as digital output */
    gpio_pin_config_t lockSolenoidConfig = {
        kGPIO_DigitalOutput,
        GPIO_LOGIC_LEVEL_LOW,
    };
    GPIO_PinInit(GPIO5, LOCK_SOLENOID, &lockSolenoidConfig);
}

/**
 * @brief Reads gear lever position inputs and updates the corresponding RTE signal.
 *
 * The function:
 *  - Samples all discrete inputs for lever positions.
 *  - Determines the current lever position based on active input.
 *  - Writes the resulting position to RTE (g_HW_LeverPosition).
 *
 * @return The resolved gear_level_possition value.
 *
 * @note If more than one input is active simultaneously, the first
 *       matching condition in the sequence P → R → N → D → 1 → 2 wins.
 */
gear_level_possition TCM_read_gear_level_possition(void)
{
	uint8 ReadParking = 0;
	uint8 ReadReverse = 0;
	uint8 ReadNeutral = 0;
	uint8 ReadDrive = 0;
	uint8 ReadFirst = 0;
	uint8 ReadSecond = 0;

	ReadParking = GPIO_PinRead(GPIO1,  PARKING_PIN);
	ReadReverse = GPIO_PinRead(GPIO1,  REVERSE_PIN);
	ReadNeutral = GPIO_PinRead(GPIO3,  NEUTRAL_PIN);
	ReadDrive = GPIO_PinRead(GPIO2,  DRIVE_PIN);
	ReadFirst = GPIO_PinRead(GPIO1,  FIRST_PIN);
	//ReadSecond = GPIO_PinRead(GPIO1,  SECOND_PIN);

	if (ReadParking == GPIO_LOGIC_LEVEL_HIGH){
		Rte_write_g_HW_LeverPosition(PARKING);
	}
	else if (ReadReverse == GPIO_LOGIC_LEVEL_HIGH){
		Rte_write_g_HW_LeverPosition(REVERSE);
	}
	else if (ReadNeutral == GPIO_LOGIC_LEVEL_HIGH){
		Rte_write_g_HW_LeverPosition(NEUTRAL);
	}
	else if (ReadDrive == GPIO_LOGIC_LEVEL_HIGH){
		Rte_write_g_HW_LeverPosition(DRIVE);
	}
	else if (ReadFirst == GPIO_LOGIC_LEVEL_HIGH){
		Rte_write_g_HW_LeverPosition(FIRST);
	}
//	else if (ReadSecond == GPIO_LOGIC_LEVEL_HIGH){
//	Rte_write_g_HW_LeverPosition(SECOND);
//	}
}

/**
 * @brief Debounces the raw brake pedal input.
 *
 * Implements a simple time-based debounce:
 *  - If current sample differs from last sample, the debounce counter is
 *    reloaded.
 *  - If samples are equal, the counter is decremented down to 0.
 *  - When the counter reaches 0, the stable state is updated.
 *
 * @return Debounced brake pedal state (0 = released, 1 = pressed).
 */
uint16 IoHwAb_DebounceBrakeRaw()
{
    /* Leer el pin (0 o 1) */
    uint8_t current = GPIO_PinRead(GPIO3, BREAK_PEDAL_PIN);

    /* Detectar cambios (0→1 o 1→0) */
    if (current != lastState)
    {
        counter = DEBOUNCE_COUNT;  // reinicia contador
    }
    else
    {
        if (counter > 0)
        {
            counter--;
        }
        else
        {
            /* Estable → actualiza estado estable */
            stableState = current;
        }
    }

    lastState = current;

    /* Regresa el valor "limpio" */
    return (bool)stableState;
}

/**
 * @brief Reads the debounced brake pedal state and updates the RTE signal.
 *
 * This function:
 *  - Calls @ref IoHwAb_DebounceBrakeRaw to obtain a stable state.
 *  - Maps the boolean state to PEDAL_ON / PEDAL_OFF.
 *  - Writes the pedal position to RTE (g_HW_BrakeSW).
 *
 * @return Resolved pedal_possition value.
 */
pedal_possition TCM_read_pedal_possition(void)
{
	bool brakeRaw = IoHwAb_DebounceBrakeRaw();

	if (brakeRaw == GPIO_LOGIC_LEVEL_HIGH)
	{
		Rte_write_g_HW_BrakeSW(PEDAL_ON);
	}
	else if (brakeRaw == GPIO_LOGIC_LEVEL_LOW)
	{
		Rte_write_g_HW_BrakeSW(PEDAL_OFF);
	}
}

/**
 * @brief Updates shift solenoid outputs from RTE commands.
 *
 * The function:
 *  - Reads desired states from RTE (g_OUT_ShiftSolenoid).
 *  - Drives GPIO outputs for solenoids A, B, C, D, E accordingly.
 *
 * @note Actualmente se usa la misma señal de RTE (g_OUT_ShiftSolenoid)
 *       para todos los solenoides. Si en el futuro hay una señal distinta
 *       por solenoide, este mapeo deberá actualizarse.
 */
void TCM_set_shift_solenoids(void)
{
	uint8 ReadSolenoidA = 0;
	uint8 ReadSolenoidB = 0;
	uint8 ReadSolenoidC = 0;
	uint8 ReadSolenoidD = 0;
	uint8 ReadSolenoidE = 0;

	Rte_read_g_OUT_ShiftSolenoidA(&ReadSolenoidA);
	GPIO_PinWrite(GPIO1, SOLENOID_A_PIN, ReadSolenoidA);

	Rte_read_g_OUT_ShiftSolenoidB(&ReadSolenoidB);
	GPIO_PinWrite(GPIO1, SOLENOID_B_PIN, ReadSolenoidB);

	Rte_read_g_OUT_ShiftSolenoidC(&ReadSolenoidC);
	GPIO_PinWrite(GPIO1, SOLENOID_C_PIN, ReadSolenoidC);

	Rte_read_g_OUT_ShiftSolenoidD(&ReadSolenoidD);
	GPIO_PinWrite(GPIO1, SOLENOID_D_PIN, ReadSolenoidD);

	Rte_read_g_OUT_ShiftSolenoidE(&ReadSolenoidE);
	GPIO_PinWrite(GPIO4, SOLENOID_E_PIN, ReadSolenoidE);

}

/**
 * @brief Updates the shift-lock solenoid output from RTE command.
 *
 * This function:
 *  - Reads the desired lock solenoid state from RTE (g_OUT_ShiftLock_Solenoid).
 *  - Drives the LOCK_SOLENOID GPIO output accordingly.
 */
void TCM_set_ShiftLock_soenoid (void)
{
	uint8 ReadLockSolenoid = 0;

	Rte_read_g_OUT_ShiftLock_Solenoid(&ReadLockSolenoid);
	GPIO_PinWrite(GPIO5, LOCK_SOLENOID, ReadLockSolenoid);

}
