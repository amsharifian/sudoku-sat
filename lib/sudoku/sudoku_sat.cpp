#include "sudoku_sat.h"

#include <iostream>

namespace {

const int rows = 9;
const int columns = 9;
const int values = 9;

int toVar(int column, int row, int value) {
    assert(row >= 0 && row < rows && "Attempt to get var for nonexistant row");
    assert(column >= 0 && column < columns &&
           "Attempt to get var for nonexistant column");
    assert(value >= 0 && value < values &&
           "Attempt to get var for nonexistant value");
    return row * columns * values + column * values + value;
}

}  // namespace

//Solver::Solver(bool write_dimacs) : m_write_dimacs(write_dimacs) {
    //picosat_init();
//}

