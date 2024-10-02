cmake_minimum_required(VERSION 3.16)

project(Sep_30_QObjectList VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appSep_30_QObjectList
    main.cpp
)

qt_add_qml_module(appSep_30_QObjectList
    URI Sep_30_QObjectList
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES
        SOURCES
        SOURCES
        SOURCES
        SOURCES ItemList.h
        SOURCES Item.h
        RESOURCES data.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appSep_30_QObjectList PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appSep_30_QObjectList
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSep_30_QObjectList
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appSep_30_QObjectList
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
