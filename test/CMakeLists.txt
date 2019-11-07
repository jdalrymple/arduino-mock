message ("building tests for Arduino Mock")

add_executable(arduino-mock-test test_all.cc)

target_link_libraries(arduino-mock-test gtest gtest_main gmock)
target_link_libraries(arduino-mock-test arduino-mock)

add_test(arduino-mock arduino-mock-test)