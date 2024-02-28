include_directories(include)

add_executable("generate_files"
    src/generate_files.c
    src/ciot_ble_scn_types.c
    src/ciot_ble_types.c
    src/ciot_bridge_types.c
    src/ciot_httpc_types.c
)