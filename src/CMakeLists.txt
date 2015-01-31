cmake_minimum_required (VERSION 2.6)
 
project (gnome-connect)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../modules" ${CMAKE_MODULE_PATH})

find_package (GCrypt REQUIRED)
find_package (PkgConfig REQUIRED)
pkg_check_modules (NOTIFY REQUIRED libnotify)

include_directories (${NOTIFY_INCLUDE_DIRS} ${GCRYPT_INCLUDE_DIRS})

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
