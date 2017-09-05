cmake_minimum_required(VERSION 3.7)

## SFML
option(SFML_BUILD_NETWORK OFF)
option(SFML_BUILD_AUDIO OFF)
option(SFML_USE_STATIC_STD_LIBS OFF)
find_package(SFML COMPONENTS graphics window system)