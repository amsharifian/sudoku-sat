cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(exename sudoku-sat)

add_executable(${exename} main.cpp)
target_link_libraries(${exename} ${CMAKE_SOURCE_DIR}/lib/picosat/libpicosat.a)
target_link_libraries(${exename} sudoku )



set_target_properties(${exename} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
)

install(TARGETS ${exename}
    RUNTIME DESTINATION bin
)
