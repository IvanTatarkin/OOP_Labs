cmake_minimum_required(VERSION 3.10)

# Установите имя проекта для подкаталога
project(LW_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление директории для заголовочных файлов
include_directories(include)

# Подключение Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
    TLS_VERIFY false
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Создание библиотеки из solver.cpp
add_library(LW2_lib src/solver.cpp)

# Создание исполняемого файла для основной программы
add_executable(LW2 main.cpp)
target_link_libraries(LW2 PRIVATE LW2_lib)

# Включение тестов
enable_testing()

# Создание исполняемого файла для тестов
add_executable(LW2_tests test/test_solver.cpp)
target_link_libraries(LW2_tests PRIVATE LW2_lib gtest gmock gtest_main)

# Регистрация тестов
add_test(NAME MyProjectTests COMMAND LW2_tests)

