#include <stdio.h>   // for the printf(), scanf() command
#include <conio.h>   // for the _getch() command


void statistics(int n1, int n2, int n3, int* sum, float* avg)
{
   *sum = n1+n2+n3;
   *avg = (*sum)/3.0f;
}

int main()
{
   for (int n1=0; n1<=5; n1++)
      for (int n2 = 0.0; n2 <= 5; n2++)
         for (int n3 = 0.0; n3 <= 5; n3++)
         {
            int sum;
            float avg;
            statistics(n1,n2,n3, &sum, &avg);
            printf("\nn1=%d n2=%d n3=%d --> sum=%d, avg=%.2f", n1,n2,n3, sum, avg);
            _getch();
         }

   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}

