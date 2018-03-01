cmake_minimum_required(VERSION 2.6)
project(dexdump)

set(CMAKE_CXX_STANDARD 11)
if (UNIX)
    set(CMAKE_CXX_FLAGS_DEBUG "-g3")
endif (UNIX)

include_directories(include/)

set(HEADER_FILES
	include/SysEndian.h
	include/Leb128.h
	include/DexCode.h
	include/DexClassDef.h
	include/DexClass.h
	include/DexClassList.h
	include/DexHeader.h
	include/DexFile.h
	include/RawFile.h
	include/FileManager.h
	include/ParamParser.h
	include/Logger.h
)

set(SOURCE_FILES
	src/SysEndian.cpp
	src/Leb128.cpp
	src/DexCode.cpp
	src/DexClassDef.cpp
	src/DexClass.cpp
	src/DexClassList.cpp
	src/DexHeader.cpp
	src/DexFile.cpp
	src/RawFile.cpp
	src/FileManager.cpp
	src/ParamParser.cpp
	src/Logger.cpp
	src/main.cpp
)

if (UNIX)
    set(CMAKE_CXX_FLAGS_RELEASE "-W -Wall -Wextra -O2 -fomit-frame-pointer \
    -ffast-math -malign-double -msseregparm -msse3 -minline-all-stringops \
    -fgcse-lm -fgcse-sm -fforce-addr -pedantic-errors")
    set(CMAKE_CXX_FLAGS_DEBUG "-W -Wall -Wextra -O2 -fomit-frame-pointer \
    -ffast-math -malign-double -msseregparm -msse3 -minline-all-stringops \
    -fgcse-lm -fgcse-sm -fforce-addr -pedantic-errors -g3")
endif (UNIX)

add_executable(dexdump ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(dexdump)
