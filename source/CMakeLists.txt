cmake_minimum_required (VERSION 3.8)

project ("afread")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(utils.cmake)
fix_eclipse_generator()

if(CMAKE_CXX_COMPILER_ID MATCHES "(C|c?)lang")
	set(CLANG 1)
endif()

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus /utf-8 /WX")
endif()

if (CLANG AND NOT MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8 -Wall -Werror")
	set(AF_LD_OPTIONS "-fuse-ld=lld")
endif()

# Include sub-projects.
add_subdirectory ("affinity")
add_subdirectory ("afread")
add_subdirectory ("zstd")
add_subdirectory ("miniz")
add_subdirectory ("cxxopts")


