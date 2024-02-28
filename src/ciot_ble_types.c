/**
 * @file ciot_ble_data.c
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
#include "ciot_ble_types.h"

static const int CIOT_IFACE_ID = 1;
static const int CIOT_IFACE_TYPE = CIOT_IFACE_TYPE_BLE;

void generate_file(const char *filename, void *filecontent, int filesize);

static ciot_ble_cfg_t cfg = {
    .mac = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC}
};

static ciot_ble_status_t status = {
    .state = CIOT_BLE_STATE_STARTED,
    .err_code = 77,
    .info = {
        .hw_mac = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66},
        .sw_mac = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF}
    }
};

static ciot_ble_req_t request = {
    .type = CIOT_BLE_REQ_SET_MAC,
    .data = {
        .set_mac = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC}
    }
};

void ciot_ble_cfg_file_create()
{
    ciot_msg_t msg = {
        .id = 0,
        .type = CIOT_MSG_TYPE_GET_CONFIG,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.ble.config = cfg};
    generate_file(CIOT_DATA_FILES_DIR "ciot_ble_cfg.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.ble.config));
}

void ciot_ble_status_file_create()
{
    ciot_msg_t msg = {
        .id = 1,
        .type = CIOT_MSG_TYPE_GET_STATUS,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.ble.status = status,
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_ble_status.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.ble.status));
}

void ciot_ble_req_file_create()
{
    ciot_msg_t msg = {
        .id = 2,
        .type = CIOT_MSG_TYPE_REQUEST,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.ble.request = request,
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_ble_request.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.ble.request));
}

void ciot_ble_generate_files()
{
    ciot_ble_cfg_file_create();
    ciot_ble_status_file_create();
    ciot_ble_req_file_create();
}
