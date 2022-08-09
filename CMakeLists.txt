cmake_minimum_required(VERSION 3.0.0)
project(json_bug VERSION 0.1.0)

include(CTest)
enable_testing()

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.1/json.tar.xz)
FetchContent_MakeAvailable(json)


add_executable(json_bug main.cpp bug.cpp)
 target_link_libraries(json_bug PRIVATE nlohmann_json::nlohmann_json)

target_compile_options(
    json_bug PRIVATE $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang>:-Wall -Wextra -Werror -fPIC -Werror=return-type -Wno-unknown-pragmas> # -O3 -Werror 
                PRIVATE $<$<COMPILE_LANG_AND_ID:CXX,GNU>:-Wall -Wextra -Werror -fPIC -Werror=return-type -Wno-unknown-pragmas> # -O3 -Werror
                PRIVATE $<$<COMPILE_LANG_AND_ID:CXX,MSVC>: >  )


                set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON" FORCE) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
