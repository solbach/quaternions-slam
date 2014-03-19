# The name of our project is "HELLO". CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.6.2)

set(PROJECT_NAME "Composition")
PROJECT ( ${PROJECT_NAME} )

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (src)

# Where CMAKE should look for ...
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Packages
find_package(Eigen3 REQUIRED)
include_directories(EIGEN3_INCLUDE_DIR)
