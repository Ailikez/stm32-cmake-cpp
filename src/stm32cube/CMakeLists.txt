# Adds sources generated by STM32CubeMX
# the "Project Location" should be this directory
# change this to "Project Name"
set(STM32CUBEMX_PROJECT_NAME "Example_project")


# glob all the files regardless of how many were generated
# because of globbing you hve to "touch" this file when there are new files
file(GLOB_RECURSE STM32CUBE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/${STM32CUBEMX_PROJECT_NAME}/Inc/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/${STM32CUBEMX_PROJECT_NAME}/Src/*.c"
)

# remove any system_stm32*.c (e.g. system_stm32f4xx.c) from sources, as it is not
# needed when using stm32-cmake (if included, gets compiled twice - linkage error)
string(REGEX REPLACE
    "\/[^;]*system_stm32....\.c"   # "/" + min num of any non-";" chars + the filename
    ""                             # remove it
    STM32CUBE_SOURCES "${STM32CUBE_SOURCES}"
)


# add STM32Cube includes and sources
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${STM32CUBEMX_PROJECT_NAME}/Inc/)
target_sources(${CMAKE_PROJECT_NAME} PUBLIC ${STM32CUBE_SOURCES})

# add "bridge" files
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC .)
target_sources(${CMAKE_PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/stm_config.h
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/stm_config.cpp
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/stm_interrupts.cpp
)
