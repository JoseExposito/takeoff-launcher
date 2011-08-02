# Project settings
project(takeoff)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(CMAKE_PREFIX_PATH /usr)
set(CMAKE_INSTALL_PREFIX /usr)

find_package(KDE4 REQUIRED)
find_package(MSGFMT REQUIRED)
include(KDE4Defaults)

add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_BINARY_DIR}
        ${KDE4_INCLUDES}
)

# Translations
add_subdirectory(translations)

# Add source code
add_subdirectory(src/takeoff)
add_subdirectory(src/takeoff/config)
add_subdirectory(src/takeoff/model/favorites)
add_subdirectory(src/takeoff/model/qtxdg)
add_subdirectory(src/takeoff/takeoff_widget)
add_subdirectory(src/takeoff/takeoff_widget/parts)
kde4_add_ui_files(Takeoff_SRCS src/takeoff/config/ConfigForm.ui)

# Plasmoid settings and instalation
kde4_add_plugin(plasma_applet_takeoff ${Takeoff_SRCS})
target_link_libraries(plasma_applet_takeoff
        ${KDE4_PLASMA_LIBS}
        ${KDE4_KDEUI_LIBS}
        ${KDE4_KIO_LIBRARY}
        ${QT_QTXML_LIBRARY}
)

install(TARGETS plasma_applet_takeoff
        DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES src/takeoff/desktop/plasma-applet-takeoff.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})
