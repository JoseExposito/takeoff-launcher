# Install script for directory: /home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/translations

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
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/locale/pl/LC_MESSAGES/plasma_applet_takeoff.mo")
FILE(INSTALL DESTINATION "/usr/share/locale/pl/LC_MESSAGES" TYPE FILE RENAME "plasma_applet_takeoff.mo" FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/translations/pl.gmo")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/locale/ca/LC_MESSAGES/plasma_applet_takeoff.mo")
FILE(INSTALL DESTINATION "/usr/share/locale/ca/LC_MESSAGES" TYPE FILE RENAME "plasma_applet_takeoff.mo" FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/translations/ca.gmo")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/locale/es/LC_MESSAGES/plasma_applet_takeoff.mo")
FILE(INSTALL DESTINATION "/usr/share/locale/es/LC_MESSAGES" TYPE FILE RENAME "plasma_applet_takeoff.mo" FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/translations/es.gmo")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/locale/tr/LC_MESSAGES/plasma_applet_takeoff.mo")
FILE(INSTALL DESTINATION "/usr/share/locale/tr/LC_MESSAGES" TYPE FILE RENAME "plasma_applet_takeoff.mo" FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/translations/tr.gmo")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/locale/gl/LC_MESSAGES/plasma_applet_takeoff.mo")
FILE(INSTALL DESTINATION "/usr/share/locale/gl/LC_MESSAGES" TYPE FILE RENAME "plasma_applet_takeoff.mo" FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/translations/gl.gmo")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/locale/it/LC_MESSAGES/plasma_applet_takeoff.mo")
FILE(INSTALL DESTINATION "/usr/share/locale/it/LC_MESSAGES" TYPE FILE RENAME "plasma_applet_takeoff.mo" FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/translations/it.gmo")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/locale/ru/LC_MESSAGES/plasma_applet_takeoff.mo")
FILE(INSTALL DESTINATION "/usr/share/locale/ru/LC_MESSAGES" TYPE FILE RENAME "plasma_applet_takeoff.mo" FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/translations/ru.gmo")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/locale/el/LC_MESSAGES/plasma_applet_takeoff.mo")
FILE(INSTALL DESTINATION "/usr/share/locale/el/LC_MESSAGES" TYPE FILE RENAME "plasma_applet_takeoff.mo" FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/translations/el.gmo")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/locale/de/LC_MESSAGES/plasma_applet_takeoff.mo")
FILE(INSTALL DESTINATION "/usr/share/locale/de/LC_MESSAGES" TYPE FILE RENAME "plasma_applet_takeoff.mo" FILES "/home/jose/Programación/C++/Proyectos/Takeoff/Takeoff/build/translations/de.gmo")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

