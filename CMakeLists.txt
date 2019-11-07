cmake_minimum_required (VERSION 2.8.8)
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build")

project(arduino-mock)

if (NOT TARGET gtest)
    add_subdirectory(lib/googletest)
endif ()

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${gtest_SOURCE_DIR}/include
  ${gtest_SOURCE_DIR}
  ${gmock_SOURCE_DIR}/include
  ${gmock_SOURCE_DIR})

add_library(arduino-mock STATIC
  src/Arduino.cc
  src/EEPROM.cc
  src/Serial.cc
  src/serialHelper.cc
  src/Spark.cc
  src/SPI.cc
  src/String.cc
  src/WiFi.cc
  src/RedBot.cc
  src/Wire.cc
)

set_target_properties(arduino-mock PROPERTIES ENABLE_EXPORTS true)

target_link_libraries(arduino-mock gtest gtest_main gmock)

option(test "Build all tests." OFF)

if (test)
    enable_testing()
    add_subdirectory(test)
endif ()