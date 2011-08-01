# Project settings
project(Takeoff)
find_package(KDE4 REQUIRED)
include(KDE4Defaults)

add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_BINARY_DIR}
        ${KDE4_INCLUDES}
)

# Translations
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
find_package(MSGFMT REQUIRED)

# Add source code
set(Takeoff_SRCS
    # /src/takeoff
    src/takeoff/MainWindow.h
    src/takeoff/MainWindow.cpp

    # /src/takeoff/config
    src/takeoff/config/Config.h
    src/takeoff/config/Config.cpp
    src/takeoff/config/ConfigForm.h
    src/takeoff/config/ConfigForm.cpp

    # /src/takeoff/model/favorites
    src/takeoff/model/favorites/Favorites.h
    src/takeoff/model/favorites/Favorites.cpp

    # /src/takeoff/model/qtxdg
    src/takeoff/model/qtxdg/xmlhelper.h
    src/takeoff/model/qtxdg/xdgmenuwidget.h
    src/takeoff/model/qtxdg/xdgmenurules.h
    src/takeoff/model/qtxdg/xdgmenureader.h
    src/takeoff/model/qtxdg/xdgmenulayoutprocessor.h
    src/takeoff/model/qtxdg/xdgmenuapplinkprocessor.h
    src/takeoff/model/qtxdg/xdgmenu_p.h
    src/takeoff/model/qtxdg/xdgmenu.h
    src/takeoff/model/qtxdg/xdgicon.h
    src/takeoff/model/qtxdg/xdgdirs.h
    src/takeoff/model/qtxdg/xdgdesktopfile.h
    src/takeoff/model/qtxdg/xdgaction.h
    src/takeoff/model/qtxdg/xmlhelper.cpp
    src/takeoff/model/qtxdg/xdgmenuwidget.cpp
    src/takeoff/model/qtxdg/xdgmenurules.cpp
    src/takeoff/model/qtxdg/xdgmenureader.cpp
    src/takeoff/model/qtxdg/xdgmenulayoutprocessor.cpp
    src/takeoff/model/qtxdg/xdgmenuapplinkprocessor.cpp
    src/takeoff/model/qtxdg/xdgmenu.cpp
    src/takeoff/model/qtxdg/xdgicon.cpp
    src/takeoff/model/qtxdg/xdgdirs.cpp
    src/takeoff/model/qtxdg/xdgdesktopfile.cpp
    src/takeoff/model/qtxdg/xdgaction.cpp
    #src/takeoff/model/qtxdg/xdgmime.h src/takeoff/model/qtxdg/xdgmime.cpp

    # /src/takeoff/takeoff_widget
    src/takeoff/takeoff_widget/TakeoffWidget.h
    src/takeoff/takeoff_widget/Launcher.h
    src/takeoff/takeoff_widget/TakeoffWidget.cpp
    src/takeoff/takeoff_widget/Launcher.cpp

    # /src/takeoff/takeoff_widget/parts
    src/takeoff/takeoff_widget/parts/PanelArea.h
    src/takeoff/takeoff_widget/parts/Panel.h
    src/takeoff/takeoff_widget/parts/PanelArea.cpp
    src/takeoff/takeoff_widget/parts/Panel.cpp
)
kde4_add_ui_files(Takeoff_SRCS src/takeoff/config/ConfigForm.ui)

add_subdirectory(translations)

# Plasmoid settings
kde4_add_plugin(plasma_applet_takeoff ${Takeoff_SRCS})
target_link_libraries(plasma_applet_takeoff
        ${KDE4_PLASMA_LIBS}
        ${KDE4_KDEUI_LIBS}
        ${KDE4_KIO_LIBRARY}
        ${QT_QTXML_LIBRARY}
)

install(TARGETS plasma_applet_takeoff
        DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES plasmoid/plasma-applet-takeoff.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})
