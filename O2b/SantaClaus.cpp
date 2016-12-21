#include "SantaClaus.h"
#include <stdio.h>
#include "Present.h"
#include <windows.h>


SantaClaus::SantaClaus(XmasTree* t)
{
   tree = t;
}

void SantaClaus::simulate()
{
   printf("Here is SantaClaus! I have a new present for you\n");

   PlaySound(TEXT("sounds/santaclaus.wav"), NULL, SND_FILENAME);

   char* present_names[5] = {
      "socks", "pullover", "dog", "cat", "smartphone" };
   
   printf("Choose a present: \n");
   for (int i=0; i<5; i++)
      printf("\tPresent #%d: %s\n", i, present_names[i]);
   int selection;
   scanf_s("%d", &selection);

   // generate a new present object
   Present* p = new Present( present_names[selection] );

   // put new present under xmas tree
   tree->add_present( p );
}