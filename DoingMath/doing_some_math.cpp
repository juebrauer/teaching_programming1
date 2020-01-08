#include "matrix.h"

int main()
{
   matrix m1(5, 3);
   matrix* m2 = new matrix(6, 4);
   
   m1.show_info();
   m2->show_info();
}


