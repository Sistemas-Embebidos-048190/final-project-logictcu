/*
 * @file    Rte_os.h
 * @brief   OS integration header for the RTE / TCM application.
 *
 * This header declares the top-level API used to initialize all RTE-related
 * FreeRTOS tasks and start the scheduler.
 *
 * The implementation in Rte_os.c is responsible for creating:
 *  - Rte_task          : Periodic I/O update (IoHwAb)
 *  - Rte_Task_logic    : Periodic TCU_step() logic
 *  - Rte_task_Comm_Tx  : Communication transmit task (stub)
 *  - Rte_task_Comm_Rx  : Communication receive task (stub)
 *  - Rte_task_swc      : SWC execution task (stub)
 *
 *  Created on: 27 nov. 2025
 *      Author: bruno
 */

#ifndef RTE_OS_H_
#define RTE_OS_H_

/* **********************************************************************
 * Includes
 * *********************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "tcu.h"

/* **********************************************************************
 * API Prototypes
 * *********************************************************************/
/**
 * @brief Creates all RTE-related tasks and starts the FreeRTOS scheduler.
 *
 * This function:
 *  - Creates all application tasks (IoHwAb, logic, communication, SWC).
 *  - Starts the OS scheduler via vTaskStartScheduler().
 *
 * It does not return under normal operation. If any task creation fails,
 * it will enter an infinite loop.
 *
 * Typically called once from main() after basic MCU initialization.
 */
void Rte_task_Init();

static void Rte_task(void *pvParameters);
static void Rte_Task_logic(void *pvParameters);
static void Rte_task_Comm_Tx(void *pvParameters);
static void Rte_task_Comm_Rx(void *pvParameters);
static void Rte_task_swc(void *pvParameters);


#endif /* RTE_OS_H_ */
