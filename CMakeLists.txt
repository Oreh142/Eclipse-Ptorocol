cmake_minimum_required(VERSION 3.10)
project(EclipseProtocol LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск исходных файлов
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/include/*.h" "${CMAKE_SOURCE_DIR}/include/*.hpp")

# Создание исполняемого файла
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Пути для заголовочных файлов
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")

# Опционально: включениеwarnings и оптимизаций
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-g> $<$<CONFIG:Release>:-O3>)