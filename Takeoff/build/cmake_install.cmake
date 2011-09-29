# Install script for directory: /home/jose/Programación/C++/Proyectos/Takeoff/Takeoff

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RELEASE")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/usr/lib/kde4/plasma_applet_takeoff.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/kde4/plasma_applet_takeoff.so")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/lib/kde4/plasma_applet_takeoff.so"
         RPATH "")
  ENDIF()
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/kde4/plasma_applet_takeoff.so")
FILE(INSTALL DESTINATION "/usr/lib/kde4" TYPE MODULE FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/lib/plasma_applet_takeoff.so")
  IF(EXISTS "$ENV{DESTDIR}/usr/lib/kde4/plasma_applet_takeoff.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/kde4/plasma_applet_takeoff.so")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/lib/kde4/plasma_applet_takeoff.so")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/kde4/services/plasma-applet-takeoff.desktop")
FILE(INSTALL DESTINATION "/usr/share/kde4/services" TYPE FILE FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/installation/plasma-applet-takeoff.desktop")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/translations/cmake_install.cmake")
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/src/takeoff/cmake_install.cmake")
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/src/takeoff/model/config/cmake_install.cmake")
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/src/takeoff/model/favorites/cmake_install.cmake")
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/src/takeoff/model/menu/cmake_install.cmake")
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/src/takeoff/model/krunner/cmake_install.cmake")
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/src/takeoff/view/config_forms/cmake_install.cmake")
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/src/takeoff/view/takeoff_widget/cmake_install.cmake")
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/src/takeoff/view/takeoff_widget/util/cmake_install.cmake")
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/src/takeoff/view/takeoff_widget/menu/cmake_install.cmake")
  INCLUDE("/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/src/takeoff/view/takeoff_widget/search/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
