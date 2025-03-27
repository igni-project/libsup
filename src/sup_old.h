/* sup.h
 * Data structures in the SUP standard */

#ifndef _LIBSUP_SUP_H
#define _LIBSUP_SUP_H 1

#include <stdint.h>
#include <sup_preproc.h>

/* Version of Scene Update Protocol used by library
 * Current version: v1.0 */
#define SUP_VERSION 0

/* Error codes */
enum {
	SUP_ERROR_INVALID_PROTOCOL_VERSION = 0,
	SUP_ERROR_ASSET_NOT_FOUND,
	SUP_ERROR_ACTION_NOT_FOUND,
	SUP_ERROR_FILE_IMPORT_FAILED,
	SUP_ERROR_ID_ALREADY_TAKEN,
	SUP_ERROR_INVALID_OPCODE
};

/* Opcodes
 * All requests are preceded by an opcode. */
typedef uint8_t sup_req_opcode;
enum {
	SUP_REQ_OPCODE_CONFIGURE_CONNECTION = 0,
	SUP_REQ_OPCODE_ASSET_LOAD,
	SUP_REQ_OPCODE_ASSET_SHOW,
	SUP_REQ_OPCODE_ASSET_HIDE,
	SUP_REQ_OPCODE_ASSET_TRANSFORM,
	SUP_REQ_OPCODE_ASSET_DESTROY,
	SUP_REQ_OPCODE_ACTION_CREATE_INSTANCE,
	SUP_REQ_OPCODE_ACTION_SET_FRAME,
	SUP_REQ_OPCODE_ACTION_SET_WEIGHT,
	SUP_REQ_OPCODE_ACTION_DESTROY_INSTANCE,
	SUP_REQ_OPCODE_VIEWPOINT_TRANSFORM,
	SUP_REQ_OPCODE_VIEWPOINT_SET_FIELD_OF_VIEW
};

/* Error response */

PACK__ typedef struct sup_err_response_t {
	sup_req_opcode req_opcode;
	int8_t error_code;
} sup_err_response __PACK;

/* Requests 
 * To simplify request reading through recv(), request structs have 
 * opcodes ommitted. */

/* 0 Configure connection */

PACK__ typedef struct sup_req_configure_connection_t {
	int8_t version;
} sup_req_configure_connection __PACK;

/* 1 Load asset */

PACK__ typedef struct sup_req_asset_load_t {
	int32_t asset_id;
	/* string: asset path */
} sup_req_asset_load __PACK;

/* 2 Show asset */

PACK__ typedef struct sup_req_asset_show_t {
	int32_t asset_id;
} sup_req_asset_show __PACK;

/* 3 Hide asset */

PACK__ typedef struct sup_req_asset_hide_t {
	int32_t asset_id;
} sup_req_asset_hide __PACK;

/* 4 Transform asset */

PACK__ typedef struct sup_req_asset_transform_t {
	int32_t asset_id;

	float x_location;
	float y_location;
	float z_location;

	float x_rotation;
	float y_rotation;
	float z_rotation;

	float x_scale;
	float y_scale;
	float z_scale;
} sup_req_asset_transform __PACK;

/* 5 Destroy asset */

PACK__ typedef struct sup_req_asset_destroy_t {
	int32_t asset_id;
} sup_req_asset_destroy __PACK;

/* 6 Create instance of action */

PACK__ typedef struct sup_req_action_create_instance_t {
	int32_t asset_id;
	int32_t action_id;
	/* string: action name */
} sup_req_action_create_instance __PACK;

/* 7 Set action frame */

PACK__ typedef struct sup_req_action_set_frame_t {
	int32_t action_id;
	int32_t frame;
} sup_req_action_set_frame __PACK;

/* 8 Set action weight */

PACK__ typedef struct sup_req_action_set_weight_t {
	int32_t action_id;
	int32_t weight;
} sup_req_action_set_weight __PACK;

/* 9 Destroy action instance */

PACK__ typedef struct sup_req_action_destroy_instance_t {
	int32_t action_id;
} sup_req_action_destroy_instance __PACK;

/* 10 Transform viewpoint */

PACK__ typedef struct sup_req_viewpoint_transform_t {
	float x_location;
	float y_location;
	float z_location;

	float x_rotation;
	float y_rotation;
	float z_rotation;
} sup_req_viewpoint_transform __PACK;

/* 11 Set viewpoint field of view */

PACK__ typedef struct sup_req_viewpoint_set_field_of_view_t {
	float fov;
} sup_req_viewpoint_set_field_of_view __PACK;

#endif

