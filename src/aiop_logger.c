/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc. All rights reserved.
 */

/*!
 * @file	aiop_logger.c
 *
 * @brief	AIOP Tool Logger, defining Logging routines/structures
 *
 */

/* Generic includes */
#include <stdio.h>

/* AIOP Tool Specific includes */
#include <aiop_logger.h>

/*
 * @brief
 * Logger initialization routine. This enabled debug/verbose mode if set by
 * caller on command line
 *
 * @param [in] d toggle for debug flag
 * @param [in] i toggle for info/verbose flag
 * @return void
 */
void init_aiopt_logger(int d, int v)
{
	_debug_flag = d;
	_verbose_flag = v;
}
