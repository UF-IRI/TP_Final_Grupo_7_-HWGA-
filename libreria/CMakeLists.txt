## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_library(libreria FUNCIONES.cpp FUNCIONES.h)
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_include_directories(libreria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
