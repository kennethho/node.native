cmake_minimum_required(VERSION 2.8)

project(http_parser)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  add_definitions(-DHTTP_PARSER_STRICT=1 -Wall -Wextra -O0 -g -ftrapv -DDEBUG -D_DEBUG)
endif()

add_library(
  http_parser_strict
#  SHARED
  ../http_parser.c)
