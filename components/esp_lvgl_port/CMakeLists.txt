include($ENV{IDF_PATH}/tools/cmake/version.cmake) # $ENV{IDF_VERSION} was added after v4.3...

if("${IDF_VERSION_MAJOR}.${IDF_VERSION_MINOR}" VERSION_LESS "4.4")
    return() 
endif()

#Get LVGL version
idf_component_get_property(lvgl_ver lvgl__lvgl COMPONENT_VERSION)
if(lvgl_ver EQUAL "")
    idf_component_get_property(lvgl_ver lvgl COMPONENT_VERSION)
endif()
message(STATUS "LVGL version: ${lvgl_ver}")

#Select folder by LVGL version
if(lvgl_ver VERSION_LESS "9.0.0")
    message(VERBOSE "Compiling esp_lvgl_port for LVGL8")
    set(PORT_FOLDER "lvgl8")
else()
    message(VERBOSE "Compiling esp_lvgl_port for LVGL9")
    set(PORT_FOLDER "lvgl9")
endif()

set(PORT_PATH "src/${PORT_FOLDER}")

idf_component_register(
        SRCS "${PORT_PATH}/esp_lvgl_port.c" "${PORT_PATH}/esp_lvgl_port_disp.c" 
        INCLUDE_DIRS "include" 
        PRIV_INCLUDE_DIRS "priv_include"
        REQUIRES "esp_lcd" 
        PRIV_REQUIRES "esp_timer")

set(ADD_SRCS "")
set(ADD_LIBS "")

idf_build_get_property(build_components BUILD_COMPONENTS)
if("espressif__button" IN_LIST build_components)
    list(APPEND ADD_SRCS "${PORT_PATH}/esp_lvgl_port_button.c")
    list(APPEND ADD_LIBS idf::espressif__button)
endif()
if("button" IN_LIST build_components)
    list(APPEND ADD_SRCS "${PORT_PATH}/esp_lvgl_port_button.c")
    list(APPEND ADD_LIBS idf::button)
endif()
if("espressif__esp_lcd_touch" IN_LIST build_components)
    list(APPEND ADD_SRCS "${PORT_PATH}/esp_lvgl_port_touch.c")
    list(APPEND ADD_LIBS idf::espressif__esp_lcd_touch)
endif()
if("esp_lcd_touch" IN_LIST build_components)
    list(APPEND ADD_SRCS "${PORT_PATH}/esp_lvgl_port_touch.c")
    list(APPEND ADD_LIBS idf::esp_lcd_touch)
endif()
if("espressif__knob" IN_LIST build_components)
    list(APPEND ADD_SRCS "${PORT_PATH}/esp_lvgl_port_knob.c")
    list(APPEND ADD_LIBS idf::espressif__knob)
endif()
if("knob" IN_LIST build_components)
    list(APPEND ADD_SRCS "${PORT_PATH}/esp_lvgl_port_knob.c")
    list(APPEND ADD_LIBS idf::knob)
endif()
if("espressif__usb_host_hid" IN_LIST build_components)
    list(APPEND ADD_SRCS "${PORT_PATH}/esp_lvgl_port_usbhid.c" "images/${PORT_FOLDER}/img_cursor.c")
    list(APPEND ADD_LIBS idf::espressif__usb_host_hid)
endif()
if("usb_host_hid" IN_LIST build_components)
    list(APPEND ADD_SRCS "${PORT_PATH}/esp_lvgl_port_usbhid.c" "images/${PORT_FOLDER}/img_cursor.c")
    list(APPEND ADD_LIBS idf::usb_host_hid)
endif()

if(ADD_SRCS)
    target_sources(${COMPONENT_LIB} PRIVATE ${ADD_SRCS})
endif()
if(ADD_LIBS)
    target_link_libraries(${COMPONENT_LIB} PRIVATE ${ADD_LIBS})
endif()
