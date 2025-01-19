cmake_minimum_required(VERSION 3.8)

project("mortest" CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ATRC_DIR "${CMAKE_SOURCE_DIR}/ATRC_2.1.0/cmake")
find_package(ATRC REQUIRED)

add_executable(mortest
    "src/main.cpp"
)

message(STATUS "ATRC library: ${ATRC_LIBRARY}")
message(STATUS "ATRC include directory: ${ATRC_INCLUDE_DIR}")
# Include ATRC headers
include_directories(${ATRC_INCLUDE_DIR})

# Link ATRC library
target_link_libraries(mortest PRIVATE ${ATRC_LIBRARY})

if(WIN32)
    add_custom_command(TARGET mortest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${ATRC_DIR}/${ATRC_NAMES}.dll"
            $<TARGET_FILE_DIR:mortest>
    )
else()
    add_custom_command(TARGET mortest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${ATRC_DIR}/${ATRC_NAMES}.so"
            $<TARGET_FILE_DIR:mortest>
    )
endif()
