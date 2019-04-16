cmake_minimum_required(VERSION 3.5)

project(exprtk VERSION 1.0.0 LANGUAGES CXX)

include_directories("./include")

# universal numbers library
find_package(UNIVERSAL REQUIRED)
include_directories(${UNIVERSAL_INCLUDE_DIRS})
message(STATUS "UNIVERSAL INCLUDE DIR" ${UNIVERSAL_INCLUDE_DIRS})

set(EXTRA_FLAGS             "")
set(EXTRA_FLAGS_DEBUG       "")
set(EXTRA_FLAGS_RELEASE     "")

set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS}         ${EXTRA_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   ${EXTRA_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${EXTRA_FLAGS_RELEASE}")

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif (MSVC)

# macro to read all the cpp files in a directory
# and create a test target for that cpp file
macro (compile_all testing prefix)
	foreach (source ${ARGN})
		get_filename_component (test ${source} NAME_WE)
		string(REPLACE " " ";" new_source ${source})
		set(test_name ${prefix}_${test})
		message(STATUS "Add test ${test_name} from source ${new_source}.")
		add_executable (${test_name} ${new_source})
		if (${testing} STREQUAL "true")
			add_test(${test_name} ${RUNTIME_OUTPUT_DIRECTORY}/${test_name})
		endif()
	endforeach (source)
endmacro (compile_all)


# pick up the executables
add_subdirectory(examples)
add_subdirectory(benchmark)
add_subdirectory(test)

