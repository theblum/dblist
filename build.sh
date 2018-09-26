#!/bin/sh
CFLAGS="-std=c++17 -g -O0 -pedantic -pipe"
WARNINGS="-Wall -Wextra -Wno-unused-variable -Wno-unused-parameter -Wno-unused-function"
LDLIBS=""
time clang++ $CFLAGS $WARNINGS $@ -o dblist dblist.cpp $LDLIBS
