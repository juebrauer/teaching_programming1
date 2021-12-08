#include <stdio.h>
#include <stdlib.h> // malloc & friends
#include <string.h>

#define SOME_VALUE 42


void show_array_vla(int rows, int cols, char A[rows][cols])
{
   // A is a VLA, a Variable Length Array
   // see:
   // https://de.wikipedia.org/wiki/Variable_Length_Array
   //
   // "The GNU C Compiler allocates memory for VLAs with automatic storage
   // duration on the stack.[4] This is the faster and more straightforward
   // option compared to heap-allocation, and is used by most compilers.""

   
   // Achtung!

   // 1.
   // "In C99, the length parameter must come before the variable-length
   // array parameter in function calls.[1] In C11, a __STDC_NO_VLA__ macro
   // is defined if VLA is not supported.[5] GCC had VLA as an extension
   // before C99, one that also extends into its C++ dialect."

   // 2.
   // "VLAs sind C-spezifisch und werden nicht vom C++-Standard übernommen.
   // C++ bietet Container-Klassen, die variable Felder ermöglichen.""
   
   for (int y=0; y<rows; y++)
   {
      for (int x=0; x<cols; x++)
         printf("%d ", A[y][x]);
      printf("\n");
   }
}


void show_array_ptr(char* B, int rows, int cols)
{
   
    for (int y=0; y<rows; y++)
    {
        for (int x=0; x<cols; x++)
        {
            printf("%d ", B[y*cols+x] );
        }
        printf("\n");
    }    
}


int main() {

    int dimY,dimX;

    printf("dimY=");
    scanf("%d", &dimY);    

    printf("dimX=");
    scanf("%d", &dimX);

    char C[dimY][dimX];

    for (int y=0; y<dimY; y++)
    {
        for (int x=0; x<dimX; x++)
            C[y][x] = SOME_VALUE;
    }   
    show_array_vla( dimY, dimX, C);
    //show_array_ptr( (char*) C, dimY, dimX);


    printf("Finished!\n");
}
