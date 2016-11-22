#include <stdio.h>   // printf()
#include <conio.h>   // getch()
#include <stdlib.h>  // malloc()
#include <string.h>


int main()
{
   char** all_notes = malloc( sizeof(char*) * 1);

   int nr_notes = 0;

   while (1)
   {
      system("cls");

      printf("Simple notebook for storing notes.\n");
      printf("Menu:\n");
      printf("1) Enter a new note\n");
      printf("2) Show all notes taken so far\n");
      printf("3) Exit program\n\n");

      char c = _getch();
      if (c=='3') break;

      if (c == '1')
      {
         printf("Ok. So enter your new note: ");

         // read in string
         #define MAX_STR_LEN 5000
         char str[MAX_STR_LEN];
         gets_s(str, MAX_STR_LEN);

         // allocate string of exact size of the note just entered
         int bytes = sizeof(char)*strlen(str) + 1;
         char* new_note = malloc(bytes);
         if (new_note == NULL)
         {
            printf("Sorry! Out of memory error!\n");
            _getch();
            continue;
         }

         // copy string from str to new_note
         strcpy_s(new_note, bytes, str);

         // store pointer to new string
         all_notes[nr_notes] = new_note;
         
         // make notebook one item larger
         nr_notes++;
         all_notes = realloc(all_notes, sizeof(char*)*(nr_notes+1));
      }

      if (c == '2')
      {
         printf("Notes stored so far: \n");
         for (int i=0; i<nr_notes; i++)
            printf("Note #%d : %s\n", i, all_notes[i]);

         printf("\n\nEnter a key to return to menu.\n");
         _getch();
      }

   } // while (forever)

} // main