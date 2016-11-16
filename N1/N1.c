#include <stdio.h>   // for the printf(), scanf() command
#include <conio.h>   // for the _getch() command
//#include <string.h>

int main()
{
   char s1[20];
   char s2[20];
   char s3[20];

   printf("Enter syllable #1: ");
   gets_s(s1, sizeof(s1));

   printf("Enter syllable #2: ");
   gets_s(s2, sizeof(s2));

   printf("Enter syllable #3: ");
   gets_s(s3, sizeof(s3));

   for (int i=1; i<=3; i++)
   {
      for (int j=1; j<=3; j++)
      {
         switch (i)
         {
            case 1: printf("%s", s1); break;
            case 2: printf("%s", s2); break;
            case 3: printf("%s", s3); break;
         }

         switch (j)
         {
            case 1: printf("%s", s1); break;
            case 2: printf("%s", s2); break;
            case 3: printf("%s", s3); break;            
         }
         printf("\n");
      }
   }

   printf("Press any key to exit this program.");
   _getch();
}