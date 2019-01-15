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


std::tuple<int, std::string, float> create_a_tuple() {

   return std::make_tuple(20, std::string("baz"), 1.2f);

}
     
int main()
{
   using namespace std;

   int quotient, remainder;

   tie(quotient, remainder) = divide(14, 3);
   cout << quotient << ',' << remainder << endl;

   auto result = divide2(14, 3);
   cout << std::get<0>(result) << ',' << std::get<1>(result) << endl;

   int i;
   std::string s;
   float f;
   std::tie(i, s, f) = create_a_tuple();
   std::cout << "the int: " << i << "\n"
      << "the string: " << s << "\n"
      << "the float: " << f << "\n";

   _getwch();
}

