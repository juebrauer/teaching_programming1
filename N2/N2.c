#include <stdio.h>   // for the printf(), scanf() command
#include <conio.h>   // for the _getch() command
#include <stdlib.h>  // for rand()
#include <string.h>  // for strcat()

int main()
{
   char* syllables[] = {"tan", "han", "klam", "ro", "ba", "lo" };

   printf("\nSyllables stored: ");
   for (int i=0; i<6; i++)
      printf("%s ", syllables[i]);
   printf("\n\n");

   for (int word_nr = 1; word_nr <= 10; word_nr++)
   {
      int rnd_nr_syllables = rand() % 4 + 2;

      int len = 0;
      char word[100] = "";
      for (int s=1; s<=rnd_nr_syllables; s++)
      {
         int rnd_idx = rand() % 6;
         strcat_s(word, 100, syllables[ rnd_idx ]);         
      }
      printf("Generated word #%d has %d letters : %s\n", word_nr, strlen(word), word );
   }

   printf("Press any key to exit this program.");
   _getch();
}