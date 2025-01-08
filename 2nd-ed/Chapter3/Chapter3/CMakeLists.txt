# CMakeList.txt : CMake project for Chapter3, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Chapter3 "Chapter3.cpp" "Chapter3.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Chapter3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
