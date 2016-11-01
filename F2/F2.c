#include <stdio.h>   // for the printf(), scanf() command
#include <conio.h>   // for the _getch() command
#include <time.h>    // clock_t, clock(), CLOCKS_PER_SEC


int fibonacci_recursive(int n)
{
   if (n==0)
      return 0;
   else
   if (n==1)
      return 1;
   else
      return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);   
} // fibonacci_recursive


int fibonacci_iterative(int n)
{
   if (n == 0) return 0;
   if (n == 1) return 1;

   int prevPrev = 0;
   int prev     = 1;
   int result   = 0;

   for (int i = 2; i <= n; i++)
   {
      result   = prev + prevPrev;
      prevPrev = prev;
      prev     = result;
   }
   return result;
} // fibonacci_iterative


int main()
{
   printf("Function test:\n");
   printf("F(6)  is according to fibonacci_recursive() %d\n", fibonacci_recursive(6));
   printf("F(6)  is according to fibonacci_iterative() %d\n", fibonacci_iterative(6));
   printf("F(12) is according to fibonacci_recursive() %d\n", fibonacci_recursive(12));
   printf("F(12) is according to fibonacci_iterative() %d\n", fibonacci_iterative(12));

   printf("\nSpeed test:\n");
   int s;
   clock_t start_time, end_time;
   float time_elapsed;

   start_time = clock();   
   s=0;
   for (int i = 0; i < 40; i++)
   {
      s+=fibonacci_recursive(i);
   }
   end_time = clock();
   printf("sum according to fibonacci_recursive() is %d\n", s);
   time_elapsed = (float)(end_time-start_time) / CLOCKS_PER_SEC;
   printf("time needed using fibonacci_recursive() is %.10f seconds\n", time_elapsed);


   start_time = clock();
   s = 0;
   for (int i = 0; i < 40; i++)
   {
      s += fibonacci_iterative(i);
   }
   end_time = clock();
   printf("sum according to fibonacci_iterative() is %d\n", s);
   time_elapsed = (float)(end_time - start_time) / CLOCKS_PER_SEC;
   printf("time needed using fibonacci_iterative() is %.10f seconds\n", time_elapsed);

   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}

