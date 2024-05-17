cmake_minimum_required(VERSION 3.15)
project(8lab)
enable_language(CXX)


add_executable(main main.cpp)
target_link_options(main PUBLIC -Llib)
include_directories("include/")
link_directories("lib/")
target_link_libraries(main
sfml-audio
sfml-graphics
sfml-window
sfml-system
sfml-network
freetype
ogg
openal
vorbis
vorbisenc
vorbisfile
udev
X11
Xrandr
OpenGL
pthread
Xcursor
)