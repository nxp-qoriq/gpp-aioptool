/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc. All rights reserved.
 */

/*!
 * @file	aiop_tool_dummy.c
 *
 * @brief	Dummy file for Unit Testing of AIOP Tool Command Line
 *
 */

#include <aiop_tool.h>
#include <aiop_cmd.h>
#include <aiop_logger.h>

/* ===========================================================================
 * AIOPT Operations Definitions
 * ===========================================================================
 */
int
dummy_perform_aiop_load(fsl_vfio_t handle, aiopt_conf_t *conf)
{
	AIOPT_DEV("Entering\n");
	AIOPT_DEV("Exiting\n");
	return AIOPT_SUCCESS;
}

int
dummy_perform_aiop_reset(fsl_vfio_t handle, aiopt_conf_t *conf)
{
	AIOPT_DEV("Entering\n");
	AIOPT_DEV("Exiting\n");
	return AIOPT_SUCCESS;
}

int
dummy_perform_aiop_get_status(fsl_vfio_t handle, aiopt_conf_t *conf)
{
	AIOPT_DEV("Entering\n");
	AIOPT_DEV("Exiting\n");
	return AIOPT_SUCCESS;
}

int
dummy_perform_aiop_gettod(fsl_vfio_t handle, aiopt_conf_t *conf)
{
	AIOPT_DEV("Entering\n");
	AIOPT_DEV("Exiting\n");
	return AIOPT_SUCCESS;
}

int
dummy_perform_aiop_settod(fsl_vfio_t handle, aiopt_conf_t *conf)
{
	AIOPT_DEV("Entering\n");
	AIOPT_DEV("Exiting\n");
	return AIOPT_SUCCESS;
}

