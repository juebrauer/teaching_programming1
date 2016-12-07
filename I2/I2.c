#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h> // strcmp()
#include <stdlib.h> // strtod()
#include <stdbool.h>

void bubble_sort(double A[], int N)
{
   bool swapped;
   do
   {
      swapped = false;
      for (int i = 0; i < N - 1; i++)
      {
         if (A[i] > A[i + 1])
         {
            double tmp=A[i];
            A[i]=A[i+1];
            A[i+1] = tmp;
            swapped = true;
         }
      }
   } while (swapped);
}


int main()
{
   // 1. get valid filename and open that file
   char fname[500];
   FILE* f;
   do {
      printf("Enter filename with absolute path --> ");
      gets_s(fname, sizeof(fname));

      f = fopen(fname, "r");

      if (f == NULL)
         printf("Error! I could not open the specified file %s\n", fname);

   } while (f == NULL);

   // 2. read in all the numbers
   char line[500];
   int counter = 0;
   double A[1000];
   while (fgets(line, sizeof(line), f))
   {
      char* errptr1;
      double d = strtod(line, &errptr1);
      printf("Number #%d: %.5f\n", counter, d);

      // if the only thing from line that cannot be converted to a double
      // by strtod() is the newline character \n and the null termination
      // character \0, then everything was ok!
      if (strcmp(errptr1, "\n") == 0)      
      {
         A[counter] = d;
      }
      else
      {
         printf("Error: some characters of the string could not be converted!\n");
         _getch();
      }         
      counter++;
   }

   // 3. sort the array using Bubble sort https://en.wikipedia.org/wiki/Bubble_sort
   bubble_sort(A,counter);

   // 4. write sorted array to another file
   char fname2[1000];
   sprintf(fname2, "%s.sorted.txt", fname);
   FILE* f2=fopen(fname2, "w");
   for (int i=0; i<counter; i++)
      fprintf(f2, "%.5f\n", A[i]);
   fclose(f2);

   printf("Press any key to exit this program.");
   _getch();
}
