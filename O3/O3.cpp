/// file: O3.cpp
///
/// solution for exercise comparing printf() and cout
///
/// for more pros and cons of printf() vs. cout see:
/// http://stackoverflow.com/questions/2872543/printf-vs-cout-in-c
///
/// ---
/// Prof. Dr. Jürgen Brauer, www.juergenbrauer.org
///

#include <stdio.h>  // for printf()
#include <conio.h>  // for getch()

#include <iostream> // for cout: cout is an object of class ostream declared in iostream
#include <iomanip>  // for setprecision()

using namespace std;

class Vec
{
   public:
      Vec(int x, int y, int z)
      {
         this->x = x;
         this->y = y;
         this->z = z;
      }

      void output()
      {
         printf("x=%d y=%d z=%d\n", x,y,z);
      }

      friend ostream& operator<<(ostream& os, const Vec& v);

   private:
      int x,y,z;
};

ostream& operator<<(ostream& os, const Vec& v)
{
   os << "x=" << v.x << " y=" << v.y << " z=" << v.z << "\n";
   return os;
}


int main()
{
  // 1. define 3 variables
  char c = '@';
  int  i = 42;
  float f = 3.14159f;


  // 2. output all 3 variables with printf() and then with cout
  //
  printf("printf: c=%c i=%d f=%f\n", c, i, f);
  cout << "cout: c=" << c << " i=" << i << " f=" << f << "\n";
  //
  // comparison:
  // -> :) printf(): syntax allows for a better overview
  //                 of string that will be outputted
  // -> :) cout: we need not to know the type specified %c, %d, %f
  printf("\n");


  // 3. output f with two decimal places, then with three decimal places
  //
  printf("printf: f=%.2f f=%.3f\n", f,f );
  cout << "cout: f=" << setprecision(2) << fixed << f << " "
             << "f=" << setprecision(3) << fixed << f << "\n";
  //
  // comparison:
  // --> :) printf(): very compact syntax compared to cout
  printf("\n");


  // 4. output f with two decimal places and
  //    fixed field length of 10 and leading zeros
  //
  printf("printf: f=%010.2f\n", f);
  cout.fill('0');
  cout << "cout: f=" << setw(10) << setprecision(2) << fixed << f << "\n";
  //
  // comparison:
  // --> :) printf(): very compact syntax compared to cout
  printf("\n");


  // 5. outputting object information
  Vec v(10,20,42);
  printf("here is vector v: "); v.output();
  cout << "here is vector v: " << v;
  _getch();

}