add_library(corelib
    tsu_bytebuf_construct.c
    tsu_bytebuf_read.c
    tsu_bytebuf_write.c
    tsu_error.c
    tsu_logger.c
    tsu_socket.c
)

target_include_directories(corelib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
# PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
)
