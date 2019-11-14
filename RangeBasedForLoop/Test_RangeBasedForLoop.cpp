#include <conio.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#include <initializer_list>


// range based for loops for own classes
// see also:
// http://antonym.org/2014/02/c-plus-plus-11-range-based-for-loops.html
//
class A
{
public:
   A()
   {
      for (int i = 0; i < 10; i++)
         v[i] = i * 100;
   }

   int* begin()
   {
      return &v[0];
   }

   int* end()
   {
      return &v[10];
   }

   int v[10];
};





int main()
{
   int intArr[] = { 0, 2, 4, 6, 11 };

   printf("\nExample #1:\n");
   for (int elem : intArr)
      printf("elem = %d\n", elem);
   _getwch();


   printf("\nExample #2:\n");
   for (auto elem : intArr)
      printf("elem = %d\n", elem);
   _getwch();


   printf("\nExample #3:\n");
   for (int elem : intArr)
      elem = elem + 100;
   for (auto elem : intArr)
      printf("elem = %d\n", elem);
   _getwch();


   printf("\nExample #4:\n");
   for (int& elem : intArr)
      elem = elem + 100;
   for (auto elem : intArr)
      printf("elem = %d\n", elem);
   _getwch();


   printf("\nExample #5:\n");
   for (int elem : {5, 10, 15, 21})
      printf("elem = %d\n", elem);
   _getwch();


   printf("\nExample #6:\n");
   // Does not work!
   /*
   const char* str = "Hello World!";
   for (char c : str)
      printf("c = %c\n", c);
   _getwch();
   */

   printf("\nExample #7:\n");
   std::string str2 = "Hello World!";
   for (char c : str2)
      printf("c = %c\n", c);
   _getwch();


   printf("\nExample #8:\n");
   std::vector<int> v = { 3, 5, 7, 11 };
   for (auto elem : v)
      printf("elem = %d\n", elem);
   _getwch();
   

   printf("\nExample #9:\n");
   std::map<std::string, int> m = { {"Kempten", 70210}, {"Augsburg", 123}, {"Zürich", 456}, {"Muenchen", 1200399}, {"Hamburg", 903009} };
   for (auto pair : m)
   {
      printf("%s ", pair.first.c_str());
      printf("--> %d\n", pair.second);
   }  
   _getwch();


   printf("\nExample #10:\n");
   A a;
   for (auto it : a)
   {
      printf("it = %d\n", it);
   }
   _getwch();


   printf("\nDemo finished!\n");
   _getwch();
}