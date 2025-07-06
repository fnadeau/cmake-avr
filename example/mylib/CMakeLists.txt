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

find_library(M_LIB m)
message(STATUS "avr-libm: ${M_LIB}")

add_avr_library(
   mylib
   SOURCES mylib.c mylib.h
   INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
   LIBS ${M_LIB}
)
