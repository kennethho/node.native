cmake_minimum_required(VERSION 2.8)

project(node_native)

ADD_SUBDIRECTORY(subtrees)

FIND_PACKAGE(Threads)

add_definitions(-std=gnu++0x -g -O0 -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64)

include_directories(
  ${node_native_SOURCE_DIR}
  ${uv_SOURCE_DIR}/include
  ${http_parser_SOURCE_DIR}
)

add_executable(
  webclient
  webclient.cpp
)
target_link_libraries(
  webclient
  uv
  http_parser
  rt
  m
  ${CMAKE_THREAD_LIBS_INIT})

add_executable(
  webserver
  webserver.cpp
)
target_link_libraries(
  webserver
  uv
  http_parser
  rt
  m
  ${CMAKE_THREAD_LIBS_INIT})

add_executable(
  file_test
  file_test.cpp
)
target_link_libraries(
  file_test
  uv
  http_parser
  rt
  m
  ${CMAKE_THREAD_LIBS_INIT})
