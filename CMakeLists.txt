cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

project(app)

include(FetchContent)

FetchContent_Declare(
    crow
    GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
    GIT_TAG 2f224d4622381ef02d47fc03d1fcbe0190f079d5 # v1.2.1 (v1.2.1.2)
)

FetchContent_MakeAvailable(crow)
find_package(SQLite3 REQUIRED)

add_executable(app db.cpp)
target_link_libraries(app PRIVATE SQLite::SQLite3)
target_include_directories(app PRIVATE ${crow_SOURCE_DIR}/include)
