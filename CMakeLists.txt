cmake_minimum_required(VERSION 3.8)

project("mortest" LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the path to the ATRC configuration file
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/ATRC_2.2.0/cmake")

# Find ATRC library using its config file
find_package(ATRC REQUIRED)

if(NOT ATRC_FOUND)
    message(FATAL_ERROR "ATRC library not found")
endif()

# Define executable
add_executable(mortest
    "src/main.cpp"
)

# Include ATRC's headers
target_include_directories(mortest PRIVATE ${ATRC_INCLUDE_DIR})

# Link the appropriate ATRC library depending on the build type
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(mortest PRIVATE ${ATRC_LIB_DEBUG})
    add_custom_command(TARGET mortest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${ATRC_DLL_DEBUG}" # Ensure the correct debug DLL is copied
        $<TARGET_FILE_DIR:mortest>
    )
else()
    target_link_libraries(mortest PRIVATE ${ATRC_LIB_RELEASE})
    add_custom_command(TARGET mortest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${ATRC_DLL_RELEASE}" # Ensure the correct release DLL is copied
        $<TARGET_FILE_DIR:mortest>
    )
endif()

# Delete and copy src\mortest.data to the build directory
add_custom_command(TARGET mortest POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/src/mortest.data"
    $<TARGET_FILE_DIR:mortest>
)

# Optionally print configuration details for debugging
message(STATUS "ATRC_INCLUDE_DIR: ${ATRC_INCLUDE_DIR}")
message(STATUS "ATRC_LIB_DEBUG: ${ATRC_LIB_DEBUG}")
message(STATUS "ATRC_LIB_RELEASE: ${ATRC_LIB_RELEASE}")
message(STATUS "ATRC_DLL_DEBUG: ${ATRC_DLL_DEBUG}")
message(STATUS "ATRC_DLL_RELEASE: ${ATRC_DLL_RELEASE}")
