/**
 * @file ciot_usb.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-10-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __CIOT_USB_DATA__H__
#define __CIOT_USB_DATA__H__

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>

#include "ciot_common_types.h"

typedef enum __attribute__((packed))
{
    CIOT_USB_STATE_STOPPED,
    CIOT_USB_STATE_STARTED,
} ciot_usb_state_t;

typedef enum __attribute__((packed))
{
    CIOT_USB_REQ_UNKNOWN,
} ciot_usb_req_type_t;

typedef struct __attribute__((packed))
{
    bool bridge_mode;
} ciot_usb_cfg_t;

typedef struct __attribute__((packed))
{
    ciot_usb_state_t state;
} ciot_usb_status_t;

typedef union __attribute__((packed))
{

} ciot_usb_req_data_u;

typedef struct __attribute__((packed))
{
    ciot_usb_req_type_t id;
    ciot_usb_req_data_u data;
} ciot_usb_req_t;

typedef union ciot_usb_event
{
    ciot_event_data_t data;
} ciot_usb_event_u;

typedef union __attribute__((packed))
{
    ciot_usb_cfg_t config;
    ciot_usb_status_t status;
    ciot_usb_req_t request;
    ciot_usb_event_u event;
} ciot_usb_data_u;

#ifdef __cplusplus
}
#endif

#endif //!__CIOT_USB_DATA__H__