#include "Present.h"
#include <string.h>
#include <stdio.h>



Present::Present(char* name_of_present)
{
   strcpy_s(name, sizeof(name), name_of_present);

   printf("Generated a new xmas present: %s\n", name);
   
}


Present::~Present()
{
}


void Present::simulate()
{
   printf("I am only a little xmas present. I am a %s\n", name);
}

char * Present::get_present_name()
{
   return name;
}
