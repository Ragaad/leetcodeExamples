# Auto-generated problem
get_filename_component(PROB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE "-" "_" PROB_TARGET ${PROB_NAME})

add_executable(${PROB_TARGET} main.cpp)
target_link_libraries(${PROB_TARGET} PRIVATE lc_common)

add_executable(${PROB_TARGET}_tests test.cpp)
target_link_libraries(${PROB_TARGET}_tests PRIVATE lc_common GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROB_TARGET}_tests)
