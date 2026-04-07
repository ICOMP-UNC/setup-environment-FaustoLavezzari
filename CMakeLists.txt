# Request the minimum version of CMake, in case of lower version throws error.
# See #https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(
    "Lab_0"
    VERSION 1.0.0
    DESCRIPTION "Basic configuration proyect"
    LANGUAGES C
)

# Enable testing
include(CTest)

# Set the C standard to C17
set(CMAKE_C_STANDARD 17)

# Include headers project
include_directories(include)

# Load Fetch Content module to download external projects
include(FetchContent)

# Download Unity to test the project, setting the variable tha holds the URL
set(UNITY_GET_URL "https://github.com/ThrowTheSwitch/Unity.git")

# Set the FetchContent to show the output of the download
set(FETCHCONTENT_QUIET OFF)

# Set the FetchContent to download the Unity project
FetchContent_Declare(
    Unity
    GIT_REPOSITORY ${UNITY_GET_URL}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
    UPDATE_COMMAND ""
)

# Set the FetchContent to make the Unity project available
FetchContent_MakeAvailable(Unity)

# Definition of the source code to compile
file(GLOB_RECURSE SOURCES "src/*.c")

# Add the executable to the project
add_executable(${PROJECT_NAME} ${SOURCES})

# Add the libraries to the project
add_subdirectory(lib/sharedlib)
add_subdirectory(lib/staticlib)

# Include the headers of the libraries
target_include_directories(${PROJECT_NAME} PUBLIC lib/sharedlib/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/staticlib/include)

# Link the libraries to the project
target_link_libraries(${PROJECT_NAME} Static_C_Lib Shared_C_Lib)

# Add the Unity library to the project if activated
if(RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(tests)
endif()