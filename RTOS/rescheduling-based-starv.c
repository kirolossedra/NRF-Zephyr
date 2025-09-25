/*
 * Copyright (c) 2017 Linaro Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

/* STEP 2 - Define stack size and scheduling priority used by each thread */
#define STACKSIZE 1024
#define THREAD0_PRIORITY 7
#define THREAD1_PRIORITY 7

int count=0;

void thread0(void)
{
	while (1) {
		count++;
		printk("Hello, I am thread0\n");
		if (count==20){
			k_thread_suspend(k_current_get());
		}
	}
}

void thread1(void)
{
	while (1) {
		printk("Hello, I am thread1\n");
		if (count==20){
			k_thread_suspend(k_current_get());
		}
	}
}

/* STEP 4 - Define and initialize the two threads */
K_THREAD_DEFINE(thread0_id, STACKSIZE, thread0, NULL, NULL, NULL,
 THREAD0_PRIORITY, 0, 0);
K_THREAD_DEFINE(thread1_id, STACKSIZE, thread1, NULL, NULL, NULL,
 THREAD1_PRIORITY, 0, 0);
