#include "sup.h"

#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int sup_config(
		int fd,
		int8_t version
		)
{
	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  a 1-byte integer		(1) = 1
	 *
	 * The total size of the request in bytes is 2. (1 + 1) */
    char req[2];

	req[0] = SUP_REQ_CODE_CONFIGURE_CONNECTION;

	/* Version of SUP protocol to use */
	req[1] = version;

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}


int sup_asset_load(
		int fd,
		int32_t id,
		const char *path
		)
{
	size_t req_sz;
	char *req;

	/* The request contains:
	 *  a 1-byte request code							(1) = 1
	 *  a 4-byte integer 								(4) = 4
	 *  a string terminated by a 1-byte null character 	min(1+n) = 1
	 *
	 * The request has a minimum total size of 6 bytes. (1 + 4 + 1) */

	req_sz = 6 + strlen(path);
	req = malloc(req_sz);

	req[0] = SUP_REQ_CODE_ASSET_LOAD;

	/* Field: asset ID */
	*(int32_t*)&req[1] = id;

	/* Field: asset file path */
	strcpy(&req[5], path);

	/* Ensure null terminator at end of string */
	req[req_sz - 1] = 0;

	if (send(fd, req, req_sz, 0) == -1)
	{
		return -1;
	}

	return 0;
}

int sup_asset_show(
		int fd,
		int32_t id
		)
{
	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  a 4-byte integer		(4) = 4
	 *
	 * The total size of the request in bytes is 5. (1 + 4) */
    char req[5];

	req[0] = SUP_REQ_CODE_ASSET_SHOW;

	/* Field: asset ID */
	*(int32_t*)&req[1] = id;

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}

int sup_asset_hide(
		int fd,
		int32_t id
		)
{
	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  a 4-byte integer		(4) = 4
	 *
	 * The total size of the request in bytes is 5. (1 + 4) */
    char req[5];

	req[0] = SUP_REQ_CODE_ASSET_HIDE;
	
	/* Field: asset ID */
	*(int32_t*)&req[1] = id;

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}

int sup_asset_tform(
		int fd,
		int32_t id,
		float x_loc,
		float y_loc,
		float z_loc,
		float x_rot,
		float y_rot,
		float z_rot,
		float x_scale,
		float y_scale,
		float z_scale
		)
{
	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  1 4-byte int 			(1 * 4) = 4
	 *  9 4-byte floats			(9 * 4) = 36
	 *
	 * The total size of the request in bytes is 41. (36 + 4 + 1) */ 
    char req[41];

	req[0] = SUP_REQ_CODE_ASSET_TRANSFORM;

	/* Field: asset ID */
	*(int32_t*)&req[1] = id;

	/* Fields: location, rotation and scale */
	*(float*)&req[5] = x_loc;
	*(float*)&req[9] = y_loc;
	*(float*)&req[13] = z_loc;
	*(float*)&req[17] = x_rot;
	*(float*)&req[21] = y_rot;
	*(float*)&req[25] = z_rot;
	*(float*)&req[29] = x_scale;
	*(float*)&req[33] = y_scale;
	*(float*)&req[37] = z_scale;


	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}

int sup_asset_destroy(
		int fd,
		int32_t id
		)
{
	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  a 4-byte integer		(4) = 4
	 *
	 * The total size of the request in bytes is 5. (1 + 4) */
    char req[5];

	req[0] = SUP_REQ_CODE_ASSET_DESTROY;

	/* Field: asset ID */
	*(int32_t*)&req[1] = id;

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}


int sup_action_load(
		int fd,
		int32_t asset_id,
		int32_t action_id,
		const char *name
		)
{
	size_t req_sz;
	char *req;

	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  2 4-byte integers		(4 * 2) = 8
	 *  a string terminated by a 1-byte null character 	min(1+n) = 1
	 *
	 * The request has a minimum total size of 10 bytes. (1 + 8 + 1) */
	req_sz = 10 + strlen(name);
	req = malloc(req_sz);

	req[0] = SUP_REQ_CODE_ACTION_CREATE_INSTANCE;

	/* Field: asset ID */
	*(int32_t*)&req[1] = asset_id;

	/* Field: action ID */
	*(int32_t*)&req[5] = action_id;

	/* Field: action name */
	strcpy(&req[9], name);

	/* Ensure null terminator at end of string */
	req[req_sz - 1] = 0;

	if (send(fd, req, req_sz, 0) == -1)
	{
		return -1;
	}

	return 0;
}

int sup_action_set_frame(
		int fd,
		int32_t id,
		int32_t frame
		)
{
	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  2 4-byte integers		(4 * 2) = 8
	 *
	 * The total size of the request in bytes is 9. (1 + 8) */
    char req[9];

	req[0] = SUP_REQ_CODE_ACTION_SET_FRAME;

	/* Field: action ID */
	*(int32_t*)&req[1] = id;

	/* Field: action frame */
	*(int32_t*)&req[5] = frame;

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}

int sup_action_set_weight(
		int fd,
		int32_t id,
		float weight 
		)
{
	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  a 4-byte integer		(4) = 4
	 *  a 4-byte float			(4) = 4
	 *
	 * The total size of the request in bytes is 9. (1 + 4 + 4) */
    char req[9];

	req[0] = SUP_REQ_CODE_ACTION_SET_WEIGHT;

	/* Field: action ID */
	*(int32_t*)&req[1] = id;

	/* Field: action weight */
	*(float*)&req[5] = weight;

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}

int sup_action_destroy(
		int fd,
		int32_t id
		)
{
	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  1 4-byte integer		(1 * 4) = 4
	 *
	 * The total size of the request in bytes is 5. (4 + 1) */ 
	char req[5];

	req[0] = SUP_REQ_CODE_ACTION_DESTROY_INSTANCE;
	
	/* Field: action ID */
	*(int32_t*)&req[1] = id;

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}


int sup_view_tform(
		int fd,
		float x_loc,
		float y_loc,
		float z_loc,
		float x_rot,
		float y_rot,
		float z_rot
		)
{
	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  6 4-byte floats			(6 * 4) = 24
	 *
	 * The total size of the request in bytes is 25. (24 + 1) */ 
	char req[25];

	req[0] = SUP_REQ_CODE_VIEWPOINT_TRANSFORM;

	/* Fields: location and rotation*/
	*(float*)&req[1] = x_loc;
	*(float*)&req[5] = y_loc;
	*(float*)&req[9] = z_loc;
	*(float*)&req[13] = x_rot;
	*(float*)&req[17] = y_rot;
	*(float*)&req[21] = z_rot;

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}

int sup_view_set_fov(
		int fd,
		float fov
		)
{
	/* The request contains:
	 *  a 1-byte request code	(1) = 1
	 *  1 4-byte float			(1 * 4) = 4
	 *
	 * The total size of the request in bytes is 5. (4 + 1) */ 
	char req[5];

	req[0] = SUP_REQ_CODE_VIEWPOINT_SET_FIELD_OF_VIEW;

	/* Field of view, a 32-bit float, is the first and only field after the
	 * request code. */	
	*(float*)&req[1] = fov;

	if (send(fd, req, sizeof(req), 0) == -1)
	{
		return -1;
	}

	return 0;
}


