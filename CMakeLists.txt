cmake_minimum_required(VERSION 3.15...4.0)

project(
	sup
	VERSION 0.1.1
	LANGUAGES C
)

add_library(
	sup
	src/sup.c
)

target_sources(
	sup
	PUBLIC
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/libsup>
)

get_target_property(CQP_PUBLIC_HEADERS sup INTERFACE_SOURCES)

set_target_properties(sup PROPERTIES PUBLIC_HEADER "${CQP_PUBLIC_HEADERS}")

target_include_directories(
	sup
	INTERFACE include/libsup
)

include(CPack)
include(GNUInstallDirs)

install(TARGETS sup)

