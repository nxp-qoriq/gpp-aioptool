/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc. All rights reserved.
 */

/*!
 * @file	aiop_tool_dummy.h
 *
 * @brief	AIOP Tool Dummy operation headers for Unit Testing of Cmd line
 *
 */

#ifndef AIOP_TOOL_DUMMY_H
#define AIOP_TOOL_DUMMY_H

#include <aiop_tool.h>
#include <aiop_cmd.h>
#include <aiop_logger.h>

/** @def AIOP_CMDSYS_UNIT_TEST
 * @brief Macro for compiling-in dummy AIOP Tool operations
 * Once enabled during compile time, no VFIO or DPAIOP code is executed
 */
/* #define AIOP_CMDSYS_UNIT_TEST	1 */

/* ===========================================================================
 * AIOPT Operations Definitions
 * ===========================================================================
 */
int dummy_perform_aiop_load(fsl_vfio_t handle, aiopt_conf_t *conf);
int dummy_perform_aiop_reset(fsl_vfio_t handle, aiopt_conf_t *conf);
int dummy_perform_aiop_get_status(fsl_vfio_t handle, aiopt_conf_t *conf);
int dummy_perform_aiop_gettod(fsl_vfio_t handle, aiopt_conf_t *conf);
int dummy_perform_aiop_settod(fsl_vfio_t handle, aiopt_conf_t *conf);

#endif
