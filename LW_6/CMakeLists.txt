cmake_minimum_required(VERSION 3.10)
project(mai-oop)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.15.2
        TLS_VERIFY false
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(LW6_npcs src/npc.cpp)
target_include_directories(LW6_npcs PRIVATE include)

add_library(LW6_array include/array.h)
set_target_properties(LW6_array PROPERTIES LINKER_LANGUAGE CXX)

add_library(LW6_editor src/editor.cpp)
target_include_directories(LW6_editor PRIVATE include)

add_library(LW6_factory src/factory.cpp)
target_include_directories(LW6_factory PRIVATE include)

add_library(LW6_visitor src/visitor.cpp)
target_include_directories(LW6_visitor PRIVATE include)

add_library(LW6_observer src/observer.cpp)
target_include_directories(LW6_observer PRIVATE include)

add_library(LW6_exceptions src/exceptions.cpp)
target_include_directories(LW6_exceptions PRIVATE include)

add_library(LW6_tools src/tools.cpp)
target_include_directories(LW6_tools PRIVATE include)

add_executable(LW6 main.cpp)
target_include_directories(LW6 PRIVATE include)

target_link_libraries(LW6_array PRIVATE LW6_exceptions)
target_link_libraries(LW6_npcs PRIVATE LW6_visitor)
target_link_libraries(LW6_editor PRIVATE LW6_array LW6_factory LW6_npcs LW6_observer LW6_exceptions)
target_link_libraries(LW6_factory PRIVATE LW6_npcs LW6_exceptions LW6_tools)
target_link_libraries(LW6_visitor PRIVATE LW6_array LW6_observer LW6_npcs LW6_tools)
target_link_libraries(LW6 PRIVATE LW6_editor LW6_observer LW6_exceptions)

enable_testing()

add_executable(LW6_tests test/test_solver.cpp)
target_include_directories(LW6_tests PRIVATE include)


target_link_libraries(LW6_tests LW6_observer LW6_editor LW6_factory LW6_npcs LW6_exceptions gtest_main)
add_test(NAME LW6_tests COMMAND LW6_tests)