cmake_minimum_required (VERSION 2.6)
 
project (gnome-connect)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../modules" ${CMAKE_MODULE_PATH})

find_package (GCrypt REQUIRED)
find_package (PkgConfig REQUIRED)
pkg_check_modules (JSON   REQUIRED json-glib-1.0)
pkg_check_modules (NOTIFY REQUIRED libnotify)

include_directories (${GCRYPT_INCLUDE_DIRS} ${JSON_INCLUDE_DIRS} ${NOTIFY_INCLUDE_DIRS})

set (main
	hello.c
	notify.c
)

add_executable (hello ${main})
target_link_libraries (hello ${NOTIFY_LIBRARIES})

set (generate
	generate.c
)
add_executable (generate ${generate})
target_link_libraries (generate ${GCRYPT_LIBRARIES})

set (gnome-connect
	gnome-connect.c
	json-message.c
	network.c
)
add_executable (gnome-connect ${gnome-connect})
target_link_libraries (gnome-connect ${JSON_LIBRARIES})
