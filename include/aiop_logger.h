/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc. All rights reserved.
 */

/*!
 * @file	aiop_cmd.c
 *
 * @brief	AIOP Tool Command Line Handling layer
 *
 */

#ifndef AIOPT_LOGGER_H
#define AIOPT_LOGGER_H

#include <stdio.h>
#include <errno.h>

unsigned short int _debug_flag;
unsigned short int _verbose_flag;

#define LOG(...)		printf(__VA_ARGS__)

#define AIOPT_INFO(format,...)	do {					\
					if (!_verbose_flag)		\
						break;			\
					LOG("INFO: "			\
					format,				\
					##__VA_ARGS__);			\
				} while(0);

#define AIOPT_PRINT(format,...)	do {					\
					LOG(format,			\
					##__VA_ARGS__);			\
				} while(0);

#define AIOPT_ERR(format,...)	do {\
					LOG("ERROR: (L%d): "		\
					format, __LINE__,		\
					##__VA_ARGS__);			\
				} while(0);

#define AIOPT_DEBUG(format,...)	do {\
					if (!_debug_flag)		\
						break;			\
					LOG("DEBUG: (%s)(L%d): "	\
					format, __func__, __LINE__,	\
					##__VA_ARGS__);			\
				} while(0);

#define AIOPT_DEV(format,...)	do {\
					if (!_debug_flag)		\
						break;			\
					LOG("DEBUG_DEV: (%s)(L%d): "	\
					format, __func__, __LINE__,	\
					##__VA_ARGS__);			\
				} while(0);

#define AIOPT_LIB_INFO(format,...)	do {\
					if (!_verbose_flag)		\
						break;			\
					LOG("INFO: "			\
					format,				\
					##__VA_ARGS__);			\
				} while(0);

void init_aiopt_logger(int d, int v);

#endif /* AIOPT_LOGGER_H */
