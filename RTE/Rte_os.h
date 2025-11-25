/*
 * tcu_types.h
 *
 *  Created on: Nov 11, 2025
 *      Author: bruno
 */

#ifndef RTE_OS_H_
#define RTE_OS_H_

void Rte_task_Init();
static void Rte_task(void *pvParameters);
static void Rte_Task_logic(void *pvParameters);
static void Rte_task_Comm_Tx(void *pvParameters);
static void Rte_task_Comm_Rx(void *pvParameters);
static void Rte_task_swc(void *pvParameters);

#endif /* RTE_OS_H_ */
