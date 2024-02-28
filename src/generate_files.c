/**
 * @file generate_files.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>

#include "ciot_msg_types.h"

void ciot_ble_scn_generate_files();
void ciot_ble_generate_files();
void ciot_bridge_generate_files();
void ciot_httpc_generate_files();

void generate_file(const char *filename, void *filecontent, int filesize);

int main(int argc, char const *argv[])
{
    ciot_ble_scn_generate_files();
    ciot_ble_generate_files();
    ciot_bridge_generate_files();
    ciot_httpc_generate_files();
    return 0;
}

void generate_file(const char *filename, void *filecontent, int filesize)
{
    FILE *file = fopen(filename, "w");
    fwrite(filecontent, filesize, 1, file);
    printf("%s generated!\n", filename);
    fclose(file);
}
