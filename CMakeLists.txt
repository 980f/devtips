cmake_minimum_required(VERSION 3.17)
# name your project, sets ${PROJECT_NAME}
project(devtip)

# project language options, there will be defaults.
set(CMAKE_CXX_STANDARD 17)

#processor selection:
include(cortexm/stm32/f407.cmake)
#the above includes a shared file for compiler setup.

#project files are out of line for maximal file sharing with minimal boilerplate.
include(${PROJECT_SOURCE_DIR}/devtip.cmake)

#it would be nice if we could define the things herein sooner, but I haven't figured out how to forward reference the source list.
include(cortexm/postamble.cmake)
