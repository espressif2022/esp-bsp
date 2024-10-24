idf_component_register(SRCS "display_main.c" "lvgl_demo_ui.c"
                    INCLUDE_DIRS ".")

lvgl_port_create_c_image("images/esp_logo.png" "images/gen/" "ARGB8888" "NONE")
lvgl_port_create_c_image("images/esp_text.png" "images/gen/" "ARGB8888" "NONE")
lvgl_port_add_images(${COMPONENT_LIB} "images/gen/")

spiffs_create_partition_assets(
    storage
    "./images"
    FLASH_IN_PROJECT
    MMAP_FILE_SUPPORT_FORMAT ".png"
    MMAP_SUPPORT_RAW
    MMAP_RAW_COLOR_FORMAT "ARGB8888"
)
