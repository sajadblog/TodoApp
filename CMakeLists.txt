cmake_minimum_required(VERSION 3.9)
project(qt_assignment LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)
find_package(QT NAMES Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)
set( LIBRARIES
    PRIVATE Qt${QT_VERSION_MAJOR}::Core
    PRIVATE Qt${QT_VERSION_MAJOR}::Quick
    )
set(PROJECT_SOURCES
    main.cpp
    src/TodoApp.cpp
    src/TodoModel.cpp
)
set(PROJECT_HEADERS
    include/Structs.h
    include/Enums.h
    include/TodoApp.h
    include/TodoModel.h
    )
set (PROJECT_RESOURCE
    qml/qml.qrc
    resources/resources.qrc
    )
qt5_add_resources(RESOURCE_ADDED ${PROJECT_RESOURCE})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${RESOURCE_ADDED})

target_compile_definitions(${PROJECT_NAME}
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
