##########################################################################
# "THE ANY BEVERAGE-WARE LICENSE" (Revision 42 - based on beer-ware
# license):
# <dev@layer128.net> wrote this file. As long as you retain this notice
# you can do whatever you want with this stuff. If we meet some day, and
# you think this stuff is worth it, you can buy me a be(ve)er(age) in
# return. (I don't like beer much.)
#
# Matthias Kleemann
##########################################################################

cmake_minimum_required(VERSION 3.10)

macro(default_env_value varname default_value)
    if(NOT DEFINED ENV{${varname}})
        set(${varname} "${default_value}")
    else()
        set(${varname} "$ENV{${varname}}")
    endif()
endmacro()

### TOOLCHAIN SETUP AREA #################################################
# Set any variables used in the toolchain prior project() call. In that
# case they are already set and used.
##########################################################################

##########################################################################
# tools to beused for programming the AVR
##########################################################################
default_env_value(AVR_UPLOADTOOL "avrdude")
default_env_value(AVR_PROGRAMMER "avrispmkII")
default_env_value(AVR_UPLOADTOOL_PORT "usb")

##########################################################################
# AVR and fuses needs to be set
##########################################################################
default_env_value(AVR_MCU "atmega16")
set(AVR_H_FUSE 0xd9)
set(AVR_L_FUSE 0xc3)

set(MCU_SPEED "4000000")

### END TOOLCHAIN SETUP AREA #############################################

# Intentionally left blank, due to a different approach of using the
# toolchain file via -DCMAKE_TOOLCHAIN_FILE=path/to/generic-gcc-avr.cmake
# at the cmake command line call
#
# include(../generic-gcc-avr.cmake)

##########################################################################
# name your project
##########################################################################
project(AVR-EXAMPLE LANGUAGES C ASM)

# Use std=gnu99 for AVR projects
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

##########################################################################
# status messages
##########################################################################
message(STATUS "Current uploadtool is: ${AVR_UPLOADTOOL}")
message(STATUS "Current programmer is: ${AVR_PROGRAMMER}")
message(STATUS "Current upload port is: ${AVR_UPLOADTOOL_PORT}")
message(STATUS "Current uploadtool options are: ${AVR_UPLOADTOOL_OPTIONS}")
message(STATUS "Current MCU is set to: ${AVR_MCU}")
message(STATUS "Current H_FUSE is set to: ${AVR_H_FUSE}")
message(STATUS "Current L_FUSE is set to: ${AVR_L_FUSE}")

##########################################################################
# needs to be defined for AVR toolchain
##########################################################################

##########################################################################
# status messages for generating
##########################################################################
message(STATUS "Set CMAKE_FIND_ROOT_PATH to ${CMAKE_FIND_ROOT_PATH}")

##########################################################################
# compiler options for all build types
##########################################################################

add_definitions("-pedantic")
add_definitions("-pedantic-errors")

##########################################################################
# building library and application in their subdirectories
##########################################################################
add_subdirectory(mylib)
add_subdirectory(app)

##########################################################################
# testing functions w/o source files - gets FATAL_ERROR
##########################################################################
# add_avr_executable(test_breaks_generation)
# add_avr_library(mytestlib_breaks_generation)

##########################################################################
# use default documentation target
##########################################################################
set(DOXYGEN_CONF_IN "doxygen.conf")
include("${PROJECT_SOURCE_DIR}/../Modules/defaultDocuTarget.cmake")


