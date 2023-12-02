
set(HEADER_LIST "${CMAKE_SOURCE_DIR}/include/harvester.h")

find_package(Threads REQUIRED)

add_library(harvester_library harvester.cpp ../include/harvester.h 
                #  ../src/psionic_reader.cpp ../include/psionic_reader.h
                 ../include/ThreadsafeData.h
                 ../include/ThreadsafeArray.h
                #  ../src/BlockHarvester.cpp ../include/BlockHarvester.h
)

target_include_directories(harvester_library PUBLIC ../include jsoncpp_object jsoncpp_static ${CMAKE_SOURCE_DIR}/build/_deps/jsoncpp-src/include)

target_link_libraries(harvester_library  Threads::Threads
    # /usr/lib/x86_64-linux-gnu/libpthread.so
)

set_property(TARGET harvester_library PROPERTY CXX_STANDARD 17 )