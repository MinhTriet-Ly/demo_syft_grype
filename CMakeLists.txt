cmake_minimum_required(VERSION 3.16)
project(demo_zlib_grype)

set(CONAN_BUILD_INFO ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

if(NOT EXISTS ${CONAN_BUILD_INFO})
    message(STATUS "Running 'conan install'...")
    execute_process(
        COMMAND conan install ${CMAKE_SOURCE_DIR} --build missing -g cmake
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()

if(EXISTS ${CONAN_BUILD_INFO})
    include(${CONAN_BUILD_INFO})
    conan_basic_setup()
else()
    message(ERROR "The file ${CONAN_BUILD_INFO} does not exist.")
endif()

add_executable(main main.cpp)
target_link_libraries(main ${CONAN_LIBS})