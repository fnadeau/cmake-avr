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

### TOOLCHAIN SETUP AREA #################################################
# Set any variables used in the toolchain prior project() call. In that
# case they are already set and used.
##########################################################################

##########################################################################
# tools to beused for programming the AVR
##########################################################################
set(AVR_UPLOADTOOL avrdude)
set(AVR_PROGRAMMER avrispmkII)
set(AVR_UPLOADTOOL_PORT usb)

##########################################################################
# AVR and fuses needs to be set
##########################################################################
set(AVR_MCU atmega32)
set(AVR_H_FUSE 0xd9)
set(AVR_L_FUSE 0xc3)

set(MCU_SPEED "4000000")

### END TOOLCHAIN SETUP AREA #############################################

include(../generic-gcc-avr.cmake)

##########################################################################
# name your project
##########################################################################
project(AVR-CPP-EXAMPLE LANGUAGES CXX)

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
# status messages for generating
##########################################################################
message(STATUS "Set CMAKE_FIND_ROOT_PATH to ${CMAKE_FIND_ROOT_PATH}")
message(STATUS "Set CMAKE_SYSTEM_INCLUDE_PATH to ${CMAKE_SYSTEM_INCLUDE_PATH}")
message(STATUS "Set CMAKE_SYSTEM_LIBRARY_PATH to ${CMAKE_SYSTEM_LIBRARY_PATH}")

##########################################################################
# compiler options for all build types
##########################################################################
add_definitions("-pedantic")
add_definitions("-pedantic-errors")

##########################################################################
# include search paths
##########################################################################
include_directories(${AVR-CPP-EXAMPLE_SOURCE_DIR}/mycpplib)

##########################################################################
# building library and application in their subdirectories
##########################################################################
add_subdirectory(mycpplib)
add_subdirectory(cppapp)

##########################################################################
# use default documentation target
##########################################################################
include("${PROJECT_SOURCE_DIR}/../Modules/defaultDocuTarget.cmake")


