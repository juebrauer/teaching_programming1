#pragma once

#define EXPORT_THIS __declspec(dllexport)

// when creating a DLL
//class EXPORT_THIS  matrix

// when creating a static lib
class matrix
{
public:

   // generate a new matrix
   matrix(int nr_rows, int nr_cols);
   
   // show some information about this matrix
   void show_info();

private:

   // stores the number of rows of this matrix
   int nr_rows;

   // stores the number of cols of this matrix
   int nr_cols;

};
