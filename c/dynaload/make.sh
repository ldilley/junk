#!/bin/sh
gcc dynaload.c -ldl -o dynaload
gcc -c -fPIC sum.c
gcc -c -fPIC half.c
gcc -c -fPIC print_message.c
gcc -o libexample.so -shared -fPIC sum.o half.o print_message.o
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`
