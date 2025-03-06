# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Имя проекта
project(SysInfoHelper C)

# Установка стандарта C
set(CMAKE_C_STANDARD 99)

# Автоматический поиск исходных файлов
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.c")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.h")

# Добавление исполняемых файлов
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)
