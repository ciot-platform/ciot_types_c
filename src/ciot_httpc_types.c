/**
 * @file ciot_httpc_data.c
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
#include "ciot_httpc_types.h"

static const int CIOT_IFACE_ID = 3;
static const int CIOT_IFACE_TYPE = CIOT_IFACE_TYPE_HTTP_CLIENT;

void generate_file(const char *filename, void *filecontent, int filesize);

static ciot_httpc_cfg_t config = {
    .url = "http://example.com",
    .method = CIOT_HTTPC_METHOD_GET,
    .transport = CIOT_HTTPC_TRANSPORT_TCP,
    .timeout = 5000
};

static ciot_httpc_status_t status = {
    .state = CIOT_HTTPC_STATE_ERROR,
    .error = CIOT_ERR_RECV_DATA
};

ciot_httpc_req_t request = {
    .type = CIOT_HTTPC_REQ_SEND_DATA,
    .data.send = {
        .cfg = {
            .url = "http://example.com/api",
            .method = CIOT_HTTPC_METHOD_POST,
            .transport = CIOT_HTTPC_TRANSPORT_TCP,
            .timeout = 10000
        },
        .body = "Hello World!",
        .content_length = 13
    }
};

void ciot_httpc_cfg_file_create()
{
    ciot_msg_t msg = {
        .id = 0,
        .type = CIOT_MSG_TYPE_GET_CONFIG,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.httpc.config = config
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_httpc_cfg.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.httpc.config));
}

void ciot_httpc_status_file_create()
{
    ciot_msg_t msg = {
        .id = 1,
        .type = CIOT_MSG_TYPE_GET_STATUS,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.httpc.status = status,
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_httpc_status.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.httpc.status));
}

void ciot_httpc_req_file_create()
{
    ciot_msg_t msg = {
        .id = 2,
        .type = CIOT_MSG_TYPE_REQUEST,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.httpc.request = request,
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_httpc_request.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.httpc.request));
}

void ciot_httpc_generate_files()
{
    ciot_httpc_cfg_file_create();
    ciot_httpc_status_file_create();
    ciot_httpc_req_file_create();
}
