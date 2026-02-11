cmake_minimum_required(VERSION 3.16)

project(LomionReader VERSION 1.1)

if(MSVC)
    set(CMAKE_USE_WIN32_THREADS_INIT 1)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
else()
    set(CMAKE_THREAD_LIBS_INIT "-lpthread")
    set(CMAKE_HAVE_THREADS_LIBRARY 1)
    set(CMAKE_USE_WIN32_THREADS_INIT 0)
    set(CMAKE_USE_PTHREADS_INIT 1)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    add_compile_options("-std=c++17")
    add_compile_options(-pthread)
endif()
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_C_STANDARD 17)
# set(CMAKE_C_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS ON)

# set_property(TARGET tgt PROPERTY CXX_STANDARD 17)


##############################################################################
# Dependencies

include(FetchContent)

# JSONCPP
FetchContent_Declare(jsoncpp
    GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
    GIT_TAG 1.9.5     # or a particular branch, tag or commit
    GIT_SHALLOW FALSE  # ensure submodules are checked out
)

# FetchContent_GetProperties(jsoncpp)
# if (NOT jsoncpp_POPULATED)
#     
# endif ()
FetchContent_MakeAvailable(jsoncpp)

# find_package(Boost REQUIRED COMPONENTS system filesystem)


## Threads
find_package(Threads REQUIRED)
message(STATUS "threads found: ${Threads_FOUND}")

##############################################################################
# Copy html files
message("-- Copying HTML files...")
file(GLOB MONSTER_FILES
    "cmm/*.html"
    # "cmm_testing/*.php"
    # "cmm_testing/*.html"
)
message("jsoncpp include" ${CMAKE_SOURCE_DIR})

# message("target monster files")
foreach(monster_file ${MONSTER_FILES})
    message(${monster_file})
    file(COPY ${monster_file} DESTINATION ${CMAKE_SOURCE_DIR}/build/bin/monster_files )
endforeach(monster_file)
# message(${MONSTER_FILES})

file(MAKE_DIRECTORY build/bin/json_files)

add_subdirectory(harvester)

# Including

##############################################################################
# Executable

add_executable(${PROJECT_NAME} src/main.cpp)

##############################################################################
# Linking
if(MSVC)
target_link_libraries(${PROJECT_NAME} harvester_library)
else()
target_link_libraries(${PROJECT_NAME} harvester_library pthread)
endif()

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_compile_options(${PROJECT_NAME} PUBLIC "-std=c++17")

# install(DIRECTORY cmm/ DESTINATION cmm)