#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // for the printf(), scanf() command
#include <conio.h> // for the _getch() command

int main()
{
   char fname[500];

   FILE* f;
   do {
      printf("Enter filename with absolute path --> ");
      gets_s(fname, sizeof(fname));

      f = fopen(fname, "r");

      if (f==NULL)
         printf("Error! I could not open the specified file %s\n", fname);

   } while (f==NULL);

   char line[500];
   int counter=0;
   while (fgets(line, sizeof(line), f))
      counter++;

   printf("The file %s contains %d lines.\n", fname, counter);
  
   printf("Press any key to exit this program.");
   _getch();
}
