## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_library(libreria FUNCIONES.H loren.cpp pochi.cpp)
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_include_directories(libreria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
