/**
 * @file    tcu.h
 * @brief   TCU (Transmission Control Unit) application interface.
 *
 * This header declares the public API of the TCU application layer,
 * which integrates the Simulink-generated TCM_Final model with the RTE.
 *
 * Responsibilities of this module:
 *  - Initialize the TCM_Final model.
 *  - Execute one control step, reading inputs from RTE and writing
 *    model outputs back to RTE.
 *
 * Typical usage:
 *  - Call @ref TCU_init once during system startup.
 *  - Call @ref TCU_step periodically from the OS task (e.g. every 100 ms).
 */

#ifndef _TCU_H
#define _TCU_H

/* **********************************************************************
 * Includes
 * *********************************************************************/

#include "TCM_Final.h"
#include "RTE_write.h"
#include "RTE_read.h"
#include "rtwtypes.h"
#include "global_signals.h"

/* **********************************************************************
 * API Prototypes
 * *********************************************************************/

/**
 * @brief Initializes the TCU model.
 *
 * This function wraps the initialization of the Simulink-generated
 * TCM_Final model and must be called once before any call to @ref TCU_step.
 */
void TCU_init (void);

/**
 * @brief Executes one control step of the TCU logic.
 *
 * Sequence performed inside:
 *  - Reads all required inputs from the RTE.
 *  - Maps them into TCM_Final_U (Simulink input structure).
 *  - Calls TCM_Final_step().
 *  - Maps TCM_Final_Y outputs back to RTE signals.
 *
 * This function is intended to be called periodically from the OS
 * (see Rte_os.c → Rte_Task_logic).
 */
void TCU_step(void);

#endif /*_TCU_H*/
