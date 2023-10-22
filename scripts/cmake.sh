#!/bin/bash

CXX=/usr/bin/clang++ cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B build
