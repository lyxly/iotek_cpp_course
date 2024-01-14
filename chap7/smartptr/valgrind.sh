#!/bin/sh
valgrind --tool=memcheck --show-reachable=yes --leak-check=yes $1

# usage
# ./valgrind.sh ./test [executable file]
