#include <stdio.h>

class A
{
public:
   A() {
      printf("Constructor A() called.\n");
   }
   ~A() {
      printf("Destructor ~A() called.\n");
   }
   void foo() {
      printf("foo()\n");
      for (unsigned long long i=0; i<100*1024*1024; i++)
      {
          daten[i] = 42;
      }
   }
private:
   char daten[100 * 1024 * 1024];
};


int main()
{
   auto B = new int[N][100];

   // 1. Generate dynamically an array of N=5 instances of class A
   const int N = 5;   
   A* myArray = new A[N];
   printf("I have generated %d instances of class A.\n", N);

   // 2. Do something with the instances
   for (int i = 0; i < N; i++)
   {
      myArray[i].foo();
   }

   // 3. After key press, we will call delete[]
   
   delete[] myArray;

   printf("Press a key!\n");
   getchar();
   
}