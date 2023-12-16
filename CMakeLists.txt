cmake_minimum_required(VERSION 3.10)

# Enable group projects in folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(delta-studio)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(TARGET_ARCHITECTURE x64)
else()
    set(TARGET_ARCHITECTURE x86)
endif()



add_library(delta-min STATIC

    src/yds_audio_file.cpp
    src/yds_audio_parameters.cpp
    src/yds_base.cpp
    src/yds_error_handler.cpp
    src/yds_error_system.cpp
    src/yds_timing.cpp
    src/yds_timing.cpp
    src/yds_windows_audio_wave_file.cpp
    src/yds_window_system_object.cpp
    
    include/yds_allocator.h
    include/yds_audio_file.h
    include/yds_audio_parameters.h
    include/yds_base.h
    include/yds_dynamic_array.h
    include/yds_error_codes.h
    include/yds_error_handler.h
    include/yds_error_system.h
    include/yds_timing.h
    include/yds_windows_audio_wave_file.h
    include/yds_window_system_object.h
)

target_link_libraries(delta-min PUBLIC
    winmm
)

target_compile_definitions(delta-min PUBLIC _UNICODE UNICODE)

set_property(TARGET delta-min PROPERTY FOLDER "delta")


