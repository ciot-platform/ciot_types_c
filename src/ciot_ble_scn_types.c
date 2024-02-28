/**
 * @file ciot_ble_scn_data.c
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
#include "ciot_ble_scn_types.h"

static const int CIOT_IFACE_ID = 0;
static const int CIOT_IFACE_TYPE = CIOT_IFACE_TYPE_BLE_SCN;

void generate_file(const char *filename, void *filecontent, int filesize);

static const ciot_ble_scn_cfg_t cfg = {
    .interval = 100,
    .window = 50,
    .timeout = 200,
    .active = 1,
    .brigde_mode = 1,
};

static const ciot_ble_scn_status_t status = {
    .state = CIOT_BLE_SCN_STATE_ACTIVE,
    .adv_info = {
        .mac = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC},
        .rssi = -70
    },
    .err_code = 23,
};

static ciot_ble_scn_req_t request = {
    .type = CIOT_BLE_SCN_REQ_UNKNOWN,
    .data = {}
};

void ciot_ble_scn_cfg_file_create()
{
    ciot_msg_t msg = {
        .id = 0,
        .type = CIOT_MSG_TYPE_GET_CONFIG,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.ble_scn.config = cfg
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_ble_scn_cfg.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.ble_scn.config));
}

void ciot_ble_scn_status_file_create()
{
    ciot_msg_t msg = {
        .id = 1,
        .type = CIOT_MSG_TYPE_GET_STATUS,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.ble_scn.status = status,
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_ble_scn_status.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.ble_scn.status));
}

void ciot_ble_scn_req_file_create()
{
    ciot_msg_t msg = {
        .id = 2,
        .type = CIOT_MSG_TYPE_REQUEST,
        .iface.id = CIOT_IFACE_ID,
        .iface.type = CIOT_IFACE_TYPE,
        .data.ble_scn.request = request,
    };
    generate_file(CIOT_DATA_FILES_DIR "ciot_ble_scn_request.dat", &msg, CIOT_MSG_GET_SIZE(msg.data.ble_scn.request));
}

void ciot_ble_scn_generate_files()
{
    ciot_ble_scn_cfg_file_create();
    ciot_ble_scn_status_file_create();
    ciot_ble_scn_req_file_create();
}
