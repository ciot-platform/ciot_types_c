/**
 * @file ciot_bridge_data.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

#include "ciot_types_config.h"
#include "ciot_msg_types.h"
#include "ciot_bridge_types.h"

static const int CIOT_IFACE_ID = 2;
static const int CIOT_IFACE_TYPE = CIOT_IFACE_TYPE_BRIDGE;

void generate_file(const char *filename, void *filecontent, int filesize);

static ciot_bridge_cfg_t config = {
    .ifaces_id = {0x01, 0x02}
};

static ciot_bridge_status_t status = {
    .state = CIOT_BRIDGE_STATE_STARTED
};

static ciot_bridge_req_t request = {
    .type = CIOT_BRIDGE_REQ_UNKNOWN,
    .data = {}
};

void ciot_bridge_cfg_file_create()
{
    ciot_msg_t msg = {
        .id = 0,
        .type = CIOT_MSG_TYPE_GET_CONFIG,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.bridge.config = config
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_bridge_cfg.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.bridge.config));
}

void ciot_bridge_status_file_create()
{
    ciot_msg_t msg = {
        .id = 1,
        .type = CIOT_MSG_TYPE_GET_STATUS,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.bridge.status = status,
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_bridge_status.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.bridge.status));
}

void ciot_bridge_req_file_create()
{
    ciot_msg_t msg = {
        .id = 2,
        .type = CIOT_MSG_TYPE_REQUEST,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.bridge.request = request,
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_bridge_request.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.bridge.request));
}

void ciot_bridge_generate_files()
{
    ciot_bridge_cfg_file_create();
    ciot_bridge_status_file_create();
    ciot_bridge_req_file_create();
}
