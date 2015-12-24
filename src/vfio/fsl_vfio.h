/*
 * Copyright (c) 2015 Freescale Semiconductor, Inc. All rights reserved.
 */

#ifndef _FSL_VFIO_H_
#define _FSL_VFIO_H_

/*!
 * @file	fsl_vfio.h
 *
 * @brief	VFIO related definitions
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/vfs.h>
#include <sys/mman.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>
#include <stdint.h>
#include <libgen.h>
#include <include/uapi/linux/vfio.h>

/***** Macros ********/
#define VFIO_PATH_MAX		100
#define VFIO_MAX_GRP		1
#define VFIO_MAX_CONTAINERS	1

#define VFIO_SUCCESS		0
#define VFIO_FAILURE		(-1)

#define FSL_VFIO_INVALID_HANDLE	NULL

/***** Structures ********/
struct vfio_device_entry {
	int fd; /* fsl_mc root container device ?? */
	int index; /*index of child device */
	/* XXX More elements can be added here in future */
};

struct vfio_device {
	int count;		/* Number of devices in container */
	int object_index;	/* Object index, reflecting count */
	struct vfio_device_entry *dev_list;	/* Device list/array */
};

typedef void *fsl_vfio_t;	/**< VFIO object descriptor >*/

/*
 * Function Declarations
 */

fsl_vfio_t fsl_vfio_setup(const char  *vfio_container);
int fsl_vfio_destroy(fsl_vfio_t handle);
int64_t fsl_vfio_map_mcp_obj(fsl_vfio_t handle, char *mcp_obj);
int fsl_vfio_get_group_id(fsl_vfio_t handle);
int fsl_vfio_get_group_fd(fsl_vfio_t handle);
int fsl_vfio_get_dev_fd(fsl_vfio_t handle, char *dev_name);
int32_t fsl_vfio_setup_dmamap(fsl_vfio_t handle, uint64_t addr, size_t len);
void fsl_vfio_destroy_dmamap(fsl_vfio_t handle, uint64_t addr, size_t len);
int fsl_vfio_get_device_info(fsl_vfio_t handle, char *dev_name,
				struct vfio_device_info *dev_info);

#endif /* _FSL_VFIO_H */
