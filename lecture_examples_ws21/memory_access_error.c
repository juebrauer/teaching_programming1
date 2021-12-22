#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* carr = malloc(100);

    for (int i=0; i<1000; i++)
    {
        carr[i] = 'A';
    }    

    for (int i=0; i<100; i++)
    {
        printf("%c", carr[i]);
    }    
    printf("\n");

    free(carr);
}