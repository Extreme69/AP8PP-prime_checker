cmake_minimum_required(VERSION 3.16)

project(prime_number VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)


qt_add_executable(appprime_number
    main.cpp
    Main.qml
)

qt_add_qml_module(appprime_number
    URI prime_number
    VERSION 1.0
    QML_FILES
        Main.qml
    SOURCES primechecker.h primechecker.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appprime_number PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appprime_number
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appprime_number
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appprime_number
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
