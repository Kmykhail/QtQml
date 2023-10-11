find_package(Qt6 REQUIRED COMPONENTS Core Quick Widgets Help)

qt_add_qml_module(helpmodel
    URI "helpmodel"
    VERSION
        1.0
    SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/helpmodel.cpp
        ${CMAKE_CURRENT_LIST_DIR}/helpmodel.h
        ${CMAKE_CURRENT_LIST_DIR}/qmldir
    PLUGIN_TARGET helpmodel
)

set(LIST_HELP_DEPENDS
    {CMAKE_CURRENT_LIST_DIR}/documentation/helpmodelviewer.qhp
    {CMAKE_CURRENT_LIST_DIR}/documentation/helpmodelviewer.qhcp
    {CMAKE_CURRENT_LIST_DIR}/documentation/A.html)

add_custom_command(TARGET helpmodel
    PRE_BUILD
    COMMAND  qhelpgenerator ${CMAKE_CURRENT_LIST_DIR}/documentation/helpmodelviewer.qhp
             -o ${CMAKE_CURRENT_BINARY_DIR}/helpmodelviewer.qch
    DEPENDS ${LIST_HELP_DEPENDS}
    VERBATIM
)

add_custom_command(TARGET helpmodel
    PRE_BUILD
    COMMAND  qhelpgenerator ${CMAKE_CURRENT_LIST_DIR}/documentation/helpmodelviewer.qhcp
             -o ${CMAKE_CURRENT_BINARY_DIR}/helpmodelviewer.qhc
    DEPENDS ${LIST_HELP_DEPENDS}
    VERBATIM
)


target_link_libraries(helpmodel PRIVATE Qt6::Core Qt6::Quick Qt6::Widgets Qt6::Help)
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/documentation)

install(TARGETS helpmodel LIBRARY DESTINATION ${JIRATOOL_INSTALL_QML_PATH}/helpmodel)
install(FILES ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/helpmodel/qmldir DESTINATION ${JIRATOOL_INSTALL_QML_PATH}/helpmodel)
