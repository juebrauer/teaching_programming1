#include "matrix.h"
#include <iostream>


matrix::matrix(int nr_rows, int nr_cols)
{
   this->nr_rows = nr_rows;
   this->nr_cols = nr_cols;
}

void matrix::show_info()
{
   std::cout << "Matrix has " << nr_rows << " rows ";
   std::cout << "and " << nr_cols << " columns." << std::endl;
}