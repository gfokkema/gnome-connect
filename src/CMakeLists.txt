cmake_minimum_required (VERSION 2.6)
 
project (gnome-connect++)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../modules" ${CMAKE_MODULE_PATH})

add_definitions(-std=gnu++0x)

find_package (GCrypt REQUIRED)
find_package (PkgConfig REQUIRED)
pkg_check_modules (GTKMM  REQUIRED gtkmm-3.0)
pkg_check_modules (JSONCPP REQUIRED jsoncpp)
pkg_check_modules (NOTIFY REQUIRED libnotify)

include_directories (${GCRYPT_INCLUDE_DIRS} ${GTKMM_INCLUDE_DIRS} ${JSONCPP_INCLUDE_DIRS} ${NOTIFY_INCLUDE_DIRS})

set (main
	hello.cpp
	notify.cpp
)

add_subdirectory (json)
add_subdirectory (network)

add_executable (hello ${main})
target_link_libraries (hello ${NOTIFY_LIBRARIES})

set (generate
	generate.cpp
)
add_executable (generate ${generate})
target_link_libraries (generate ${GCRYPT_LIBRARIES})

set (gnome-connect
	device.cpp
	gnome-connect.cpp
)
add_executable (gnome-connect ${gnome-connect})
target_link_libraries (gnome-connect json network ${GTKMM_LIBRARIES})
