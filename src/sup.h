#ifndef _LIBSUP_SUP_H
#define _LIBSUP_SUP_H 1

#include <stdint.h>

enum {
	SUP_REQ_CODE_CONFIGURE_CONNECTION = 0,
	SUP_REQ_CODE_ASSET_LOAD,
	SUP_REQ_CODE_ASSET_SHOW,
	SUP_REQ_CODE_ASSET_HIDE,
	SUP_REQ_CODE_ASSET_TRANSFORM,
	SUP_REQ_CODE_ASSET_DESTROY,
	SUP_REQ_CODE_ACTION_CREATE_INSTANCE,
	SUP_REQ_CODE_ACTION_SET_FRAME,
	SUP_REQ_CODE_ACTION_SET_WEIGHT,
	SUP_REQ_CODE_ACTION_DESTROY_INSTANCE,
	SUP_REQ_CODE_VIEWPOINT_TRANSFORM,
	SUP_REQ_CODE_VIEWPOINT_SET_FIELD_OF_VIEW
};

int sup_config(
		int fd,
		int8_t version
		);


int sup_asset_load(
		int fd,
		int32_t id,
		const char* path
		);

int sup_asset_show(
		int fd,
		int32_t id
		);
int sup_asset_hide(
		int fd,
		int32_t id
		);

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
		);

int sup_asset_destroy(
		int fd,
		int32_t id
		);


int sup_action_load(
		int fd,
		int32_t asset_id,
		int32_t action_id,
		const char* name
		);

int sup_action_set_frame(
		int fd,
		int32_t id,
		int32_t frame
		);

int sup_action_set_weight(
		int fd,
		int32_t id,
		float weight 
		);

int sup_action_destroy(
		int fd,
		int32_t id
		);


int sup_view_tform(
		int fd,
		float x_loc,
		float y_loc,
		float z_loc,
		float x_rot,
		float y_rot,
		float z_rot
		);

int sup_view_set_fov(
		int fd,
		float fov
		);


#endif

