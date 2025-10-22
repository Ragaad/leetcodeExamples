# Problem 0001: two-sum
add_executable(p0001 main.cpp)
target_link_libraries(p0001 PRIVATE lc_common)

# Unit tests (GoogleTest)
add_executable(p0001_tests test.cpp)
target_link_libraries(p0001_tests PRIVATE lc_common GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(p0001_tests)
