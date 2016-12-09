#include <stdio.h> // for the printf(), scanf() command
#include <conio.h> // for the _getch() command

main()
{
   int n1,n2,n3;

   printf("Enter first number: ");
   scanf_s("%d", &n1);

   printf("Enter second number: ");
   scanf_s("%d", &n2);

   printf("Enter third number: ");
   scanf_s("%d", &n3);

   int sum  = n1+n2+n3;
   int prod = n1*n2*n3;
   int avg  = sum/3;

   printf("\nSum is %d", sum);       // Overflow error might happen! Try 2000000000,2000000000,2000000000
   printf("\nProduct is %d", prod);  // Overflow error might happen! Try 10000,10000,10000
   printf("\nAverage is %d", avg);   // Integer division!            Try 2,2,3

   printf("\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
