#!/bin/bash 
# Script to quickly generate a CMakeLists.txt file generating one executable for 
# each *.cc file
ls  *.cc|sed 's/\.cc//'| \
awk '{ print "add_executable(" $0" "$0".cc)"}' > executable_list.cmake
