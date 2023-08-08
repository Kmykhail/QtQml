cmake_minimum_required(VERSION 3.16)

qt_add_qml_module(randomTarget
    URI
        Test
    VERSION
        1.0
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Test.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Test.h
        ${CMAKE_CURRENT_SOURCE_DIR}/TestPlugin.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TestPlugin.h
    PLUGIN_TARGET randomTarget
)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Qml)

target_link_libraries(randomTarget
    PRIVATE Qt6::Quick
)

install(TARGETS randomTarget
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/random
)

#install(FILES qmldir DESTINATION {CMAKE_INSTALL_LIBDIR}/random)
