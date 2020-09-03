add_executable(server
    servermain.c
)

target_link_libraries(server
PUBLIC
    corelib
)

target_include_directories(server
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
# PRIVATE
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
)
