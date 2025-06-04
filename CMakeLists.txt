cmake_minimum_required(VERSION 3.15...4.0)

project(
	sup
	VERSION 0.1
	LANGUAGES C
)

add_library(
	sup
	src/sup.c
)

install(TARGETS sup)
include(CPack)

