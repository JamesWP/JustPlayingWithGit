cmake_minimum_required (VERSION 2.6)
project (GitPlay)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bld)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bld)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bld)

add_executable(listcommits listcommits.m.cpp)

message("libgit: ${LIBGIT2_LIBRARY}")

FIND_PATH(LIBGIT2_INCLUDE_DIR NAMES git2.h
   HINTS
   ${PC_LIBGIT2_INCLUDEDIR}
   ${PC_LIBGIT2_INCLUDE_DIRS}
)

FIND_LIBRARY(LIBGIT2_LIBRARIES NAMES git2
   HINTS
   ${PC_LIBGIT2_LIBDIR}
   ${PC_LIBGIT2_LIBRARY_DIRS}
)

target_link_libraries(listcommits ${LIBGIT2_LIBRARIES})

target_include_directories(listcommits PUBLIC ${LIBGIT2_INCLUDE_DIR})
