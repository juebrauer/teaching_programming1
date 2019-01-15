#include <tuple>
#include <string>
#include <conio.h>
#include <iostream>

// C++11:
std::tuple<int, int> divide(int dividend, int divisor)
{
   return  std::make_tuple(dividend / divisor, dividend % divisor);
}

// C++17:
std::tuple<int, int, int> divide2(int dividend, int divisor)
{
   return  { dividend / divisor, dividend % divisor, 123 };
}

     
int main()
{
   using namespace std;

   int quotient, remainder;

   tie(quotient, remainder) = divide(14, 3);
   cout << quotient << ',' << remainder << endl;

   auto result = divide2(14, 3);
   cout << std::get<0>(result) << ',' << std::get<1>(result) << endl;

   _getwch();
}

