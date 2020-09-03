add_executable(test_bytebuf
    test_bytebuf.c
)
add_test(           bytebuf
    test_bytebuf
)

include_directories(${CMAKE_SOURCE_DIR}/external/munit)
add_library(munit ${CMAKE_SOURCE_DIR}/external/munit/munit.c)
target_link_libraries(test_bytebuf corelib munit)
