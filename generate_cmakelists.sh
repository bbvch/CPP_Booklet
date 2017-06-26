#!/bin/bash 
# Script to quickly generate a CMakeLists.txt file generating one executable for 
# each *.cc file
ls  *.cc|sed 's/\.cc//'| \
awk 'BEGIN {print "cmake_minimum_required (VERSION 2.6)\nproject (CPP17_Snippets)"} \
 { print "add_executable(" $0" "$0".cc)"}' > CMakeLists.txt