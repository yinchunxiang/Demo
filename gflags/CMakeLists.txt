CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

# project top directory
PROJECT(demo)
MESSAGE("PROJECT_SOURCE_DIR:[${PROJECT_SOURCE_DIR}]")


# include pre-defined module and get some variables after that module executed
# Find boost 1.40
#INCLUDE(FindBoost)
#find_package(Boost 1.40.0 COMPONENTS thread unit_test_framework)
#if(NOT Boost_FOUND)
#    message(STATUS "BOOST not found, test will not succeed!")
#endif()

# include source search path
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE("CMAKE_CURRENT_SOURCE_DIR:[${CMAKE_CURRENT_SOURCE_DIR}]")

# add all source files in directory to the variable
AUX_SOURCE_DIRECTORY(. src_list)
MESSAGE("src_list:[${src_list}]")

find_package (gflags REQUIRED)
include_directories (${gflags_INCLUDE_DIR})

# generate executable files
#ADD_EXECUTABLE(${PROJECT_SOURCE_DIR} ${src_list})
add_executable(${PROJECT_NAME} ${src_list} )

link_directories(/usr/local/lib)
link_directories(/usr/lib)
link_directories(/usr/lib64)
link_directories(/lib)
link_directories(/lib64)
target_link_libraries (${PROJECT_NAME} gflags)
#target_link_libraries (${PROJECT_NAME} /usr/local/lib/libgflags.a)
target_link_libraries (${PROJECT_NAME} pthread)
