#!/bin/bash

/usr/local/bin/cmake \
	--no-warn-unused-cli \
	-DCMAKE_TOOLCHAIN_FILE:FILEPATH=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake \
	-DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
	-DCMAKE_BUILD_TYPE:STRING=Debug \
	-DCMAKE_C_COMPILER:FILEPATH=/usr/local/bin/gcc \
	-DCMAKE_CXX_COMPILER:FILEPATH=/usr/local/bin/g++ \
	-S/workspaces/hs \
	-B/workspaces/hs/build/Debug \
	-G Ninja
