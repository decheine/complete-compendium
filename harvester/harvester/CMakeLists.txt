
set(HEADER_LIST "${CMAKE_SOURCE_DIR}/include/harvester.h")

find_package(Threads REQUIRED)

add_library(harvester_library SHARED harvester.cpp ../include/harvester.h 
                #  ../src/psionic_reader.cpp ../include/psionic_reader.h
                 ../include/ThreadsafeData.h
                 ../include/ThreadsafeArray.h
                 ../include/SpecialStatblock.h
                #  ../src/BlockHarvester.cpp ../include/BlockHarvester.h
)
message(STATUS "VCPKG_ROOT: ${VCPKG_ROOT}")

# find_package(jsoncpp CONFIG REQUIRED jsoncpp_lib)

message(STATUS "jsondir:${jsoncpp_DIR}")
message(STATUS "DIR: ${js}")

find_library(jsoncpp_lib 
NAMES jsoncpp_lib
PATHS "${VCPKG_ROOT}/installed/x64-linux/lib"
)
get_target_property(JSON_INC_PATH jsoncpp_lib INTERFACE_INCLUDE_DIRECTORIES)
# get_target_property(* jsoncpp_lib INTERFACE_INCLUDE_DIRECTORIES)
include_directories(${JSON_INC_PATH})
message(STATUS "json_inc_path:${JSON_INC_PATH}")
# message(STATUS "json_inc_path:")
if(MSVC)
target_include_directories(harvester_library PUBLIC ../include ${VCPKG_ROOT}/installed/x64-windows/include)
else()
target_include_directories(harvester_library PUBLIC ../include ${VCPKG_ROOT}/installed/x64-linux/include) 
endif()

target_link_libraries(harvester_library Threads::Threads jsoncpp_lib
    # /usr/lib/x86_64-linux-gnu/libpthread.so
)

set_property(TARGET harvester_library PROPERTY CXX_STANDARD 17 )