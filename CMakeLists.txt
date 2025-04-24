cmake_minimum_required(VERSION 3.16)

project(Tropic VERSION 0.7.0 LANGUAGES CXX)

set(TROPIC_OS "")
set(TROPIC_COMPILER "")

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    set(TROPIC_OS "win32")
    set(TROPIC_COMPILER ${CMAKE_CXX_COMPILER_ID})
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(TROPIC_OS "darwin")
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(TROPIC_OS "linux")
else ()
    message(STATUS "You're using ${CMAKE_SYSTEM_NAME}")
    message(FATAL_ERROR "Can only build Tropic on win32, darwin or linux.")
endif (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_LIST_DIR}/bin/${TROPIC_OS}")

if (MSVC)
    set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_LIST_DIR}/bin/msvc/${TROPIC_OS}")
endif (MSVC)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)

if (QT_VERSION VERSION_LESS 6.0)
    set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_LIST_DIR}/bin_qt5/${TROPIC_OS}")
endif (QT_VERSION VERSION_LESS 6.0)

set(TROPIC_AT_WHERE "")

set(TROPIC_SOURCES "")

set(TROPIC_RESOURCES
    ${CMAKE_CURRENT_LIST_DIR}/rsc/Tropic.qrc)

include_directories(${CMAKE_CURRENT_LIST_DIR}/src)
include_directories(${CMAKE_CURRENT_LIST_DIR}/lib/include)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src)

set(QSCINTILLA_LIB "")
set(QSCINTILLA_ADDITIONAL_LIB "")

if (QT_VERSION VERSION_LESS 6.0)
    if (${TROPIC_OS} STREQUAL "win32")
        set(QSCINTILLA_LIB ${CMAKE_CURRENT_LIST_DIR}/lib/Qsci/win32/GNU/libqscintilla2_qt5.a)
    endif (${TROPIC_OS} STREQUAL "win32")
else ()
    if (${TROPIC_OS} STREQUAL "win32")
        if (MINGW)
            set(QSCINTILLA_LIB ${CMAKE_CURRENT_LIST_DIR}/lib/Qsci/win32/GNU/libqscintilla2_qt6.a)
        elseif (MSVC)
            set(QSCINTILLA_LIB ${CMAKE_CURRENT_LIST_DIR}/lib/Qsci/win32/MSVC/qscintilla2_qt6.lib)
            set(QSCINTILLA_ADDITIONAL_LIB ${CMAKE_CURRENT_LIST_DIR}/lib/Qsci/win32/MSVC/qscintilla2_qt6.dll)
        endif (MINGW)
    elseif (${TROPIC_OS} STREQUAL "darwin")
        set(QSCINTILLA_LIB ${CMAKE_CURRENT_LIST_DIR}/lib/Qsci/darwin/libqscintilla2_qt6.15.2.1.dylib)
    elseif (${TROPIC_OS} STREQUAL "linux")
        set(QSCINTILLA_LIB ${CMAKE_CURRENT_LIST_DIR}/lib/Qsci/linux/libqscintilla2_qt6.so.15)
    endif (${TROPIC_OS} STREQUAL "win32")
endif (QT_VERSION VERSION_LESS 6.0)

message(STATUS "QScintilla Lib is ${QSCINTILLA_LIB}")

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Tropic
        MANUAL_FINALIZATION
        ${TROPIC_SOURCES}
        ${TROPIC_RESOURCES}
    )
else ()
    if (ANDROID)
        add_library(Tropic
            SHARED
            ${TROPIC_SOURCES}
            ${TROPIC_RESOURCES}
        )
    else ()
        add_executable(Tropic
            ${TROPIC_SOURCES}
            ${TROPIC_RESOURCES}
        )
    endif (ANDROID)
endif (${QT_VERSION_MAJOR} GREATER_EQUAL 6)

target_link_libraries(Tropic PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Tropic PRIVATE Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(Tropic PRIVATE ${QSCINTILLA_LIB})

if (${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER org.BrightSoftwareFoundation.Tropic)
endif (${QT_VERSION} VERSION_LESS 6.1.0)

set_target_properties(Tropic
    PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Tropic
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Tropic)
endif()
