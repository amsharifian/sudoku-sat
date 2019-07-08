add_library(sudoku sudoku_sat.cpp)

add_library(sudoku-lib MODULE sudoku_sat.cpp)

set_target_properties(sudoku sudoku-lib PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
)
