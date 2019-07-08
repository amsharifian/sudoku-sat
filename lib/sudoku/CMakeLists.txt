add_library(sudoku sudoku_sat.cpp)
target_link_libraries(sudoku ${CMAKE_SOURCE_DIR}/lib/picosat/libpicosat.a)

set_target_properties(sudoku PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
)
