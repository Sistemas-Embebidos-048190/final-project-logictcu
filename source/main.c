/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "Rte_os.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"


#include "IoHwAb_gpio.h"
#include "IoHwAb_adc.h"
#include "IoHwAb_pwm.h"
#include "MCU.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Task priorities. */
#define hello_task_PRIORITY (configMAX_PRIORITIES - 1)
#define TCM_LPADC0_BASE  	ADC0
#define TCM_LPADC1_BASE  	ADC1

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */




int main(void)
{
    /* Init board hardware. */
    BOARD_InitHardware();
    Init_Clock_Ports();

    Rte_task_Init();
}


