cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Catch2/")

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

option(BUILD_TEST "Build tests" OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")


#find_package(Boost COMPONENTS program_options container) 
#if(Boost_FOUND)
    #include_directories(${Boost_INCLUDE_DIRS}) 
#else()
    #message( FATAL_ERROR "ctlr2bitgen needs boost.  CMake will exit.")
#endif()


include_directories(${INCLUDE_DIR})
include_directories(${HEADERS_DIR})

add_subdirectory(lib)
add_subdirectory(tools)

if(BUILD_TEST)
    enable_testing()
    set(Catch2_DIR ${PROJECT_SOURCE_DIR}/cmake/Catch2)
    find_package(Catch2 REQUIRED)
    if(Catch2_FOUND)
        include_directories(${Catch2_INCLUDE_DIRS}) 
    else()
        message( FATAL_ERROR "Couldn't find Catch2. CMake will exit.")
    endif()
    add_subdirectory(tests)
endif()



