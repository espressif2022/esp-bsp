idf_component_register(
    SRCS "dispaly_main.c" "app_disp_fs.c"
    INCLUDE_DIRS "."
    REQUIRES "esp32_p4_box" "spiffs")
