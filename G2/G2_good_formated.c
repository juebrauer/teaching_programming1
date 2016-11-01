/*
#include <stdio.h> // for the printf(), scanf() command
#include <conio.h> // for the _getch() command

int main()
{
   float capital,rate;

   // let user input his capital
   printf("Capital:");
   scanf_s("%f", &capital);

   // let user input the rate he gates from his bank
   printf("Rate:");
   scanf_s("%f", &rate);

   // show how much capital there will be after 1,2,3,...,10 years
   int year=0;
   do
   {
      capital = capital + capital*(rate / 100.0f);
      year = year + 1;
      printf("\nyear=%d: capital=%.1f",year,capital);
   } while (year<10);

   printf("\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
*/
