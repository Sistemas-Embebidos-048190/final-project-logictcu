/**
 * @file    IoHwAb.h
 * @brief   High-level Integration Header for the I/O Hardware Abstraction Layer.
 *
 * This header exposes the top-level initialization and update APIs for the
 * IoHwAb (Input/Output Hardware Abstraction) layer of the Transmission
 * Control Module (TCM).
 *
 * The IoHwAb layer provides a unified interface to all low-level hardware
 * drivers, including:
 *   - GPIO handling (inputs and outputs)
 *   - ADC sensor acquisition (speed sensors, temperature)
 *   - PWM actuation (line pressure, TCC control)
 *
 * Application software must call:
 *   - @ref Init_IO_pins   once at system startup
 *   - @ref Update_IO_pins periodically in the main loop or a cyclic task
 *
 * This module depends on:
 *   - IoHwAb_gpio.h
 *   - IoHwAb_adc.h
 *   - IoHwAb_pwm.h
 */

#ifndef _IOHWAB_H_
#define _IOHWAB_H_

/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "IoHwAb_adc.h"
#include "IoHwAb_gpio.h"
#include "IoHwAb_pwm.h"

/* **********************************************************************
 * API Prototypes
 * *********************************************************************/

/**
 * @brief Initializes all hardware peripherals used by the TCM.
 *
 * This function initializes:
 *   - GPIO inputs/outputs (pedal, lever, solenoids)
 *   - ADC pins and LPADC modules (speed + temperature sensors)
 *   - PWM outputs for hydraulic pressure and TCC control
 *
 * Must be called exactly once during system startup.
 */
void Init_IO_pins (void);


/**
 * @brief Updates all hardware I/O signals.
 *
 * This function performs, in order:
 *   - Read GPIO inputs and publish them to RTE
 *   - Write GPIO outputs based on RTE commands
 *   - Trigger ADC conversions and publish sensor values
 *   - Update PWM actuation for pressure and TCC
 *
 * Should be called periodically (e.g., in the main loop or a time-triggered task).
 */
void Update_IO_pins(void);



#endif /* _IOHWAB_H_ */
