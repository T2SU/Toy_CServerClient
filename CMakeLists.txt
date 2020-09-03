cmake_minimum_required(VERSION 3.0.0)
project(CServerClient VERSION 0.1.0)
set(cmake_build_type Debug)
set(cmake_verbose_makefile true)

add_compile_options(-Wall -Werror -Wextra)
set(cmake_c_flags_debug "-g -fsanitize=address")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(corelib)
add_subdirectory(server)
add_dependencies(server        corelib)

include(CTest)
enable_testing()
add_subdirectory(corelib-test)
