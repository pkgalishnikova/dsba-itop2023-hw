cmake_minimum_required(VERSION 3.5)

project(new VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        tablemodule.h
        tablemodule.cpp
        dialogex.ui
        dialogex.cpp;
        dialogex.h;
        proxymodel.cpp;
        proxymodel.h;
        relevantdioalog.h;
        relevantdioalog.cpp;
        relevantdioalog.ui;
        iconwidget.h;
        iconwidget.cpp;
        aboutwidget.h;
        aboutwidget.cpp;
        aboutwidget.ui;
        compairsondialog.cpp;
        compairsondialog.h;
        compairsondialog.ui;
        resource.qrc;
         new_ru.ts;
         translate_ru.ts;
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(new
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

find_package(Qt6 REQUIRED COMPONENTS LinguistTools)

qt6_add_translations(new
    TS_FILES new_ru.ts
    translate_ru.ts
    QM_FILES_OUTPUT_VARIABLE qm_files)
install(FILES ${qm_files} DESTINATION .)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET new APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(new SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(new
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(new PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(new PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS new
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(new)
endif()
