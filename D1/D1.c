#include <stdio.h>   // printf()
#include <conio.h>   // getch()
#include <stdlib.h>  // malloc()

int main()
{
   while (1)
   {
      int size_of_array;
      printf("Enter the size of the array: ");
      scanf_s("%d", &size_of_array);

      printf("Generating your array...\n");
      float* A = malloc(size_of_array * sizeof(float));

      printf("Initializing your array ...\n");
      for (int i = 0; i < size_of_array/2; i++)
         A[i] = 123.0f;
      for (int i = size_of_array/2; i < size_of_array; i++)
         A[i] = 456.0f;
      if (size_of_array % 2 == 1)
         A[size_of_array/2] = 999.0f;

      printf("Here are all the values of your array ...\n");
      for (int i = 0; i < size_of_array; i++)
         printf("A[%d]=%.1f\n", i, A[i]);

      printf("Deallocating the array ...\n");
      free(A);

      printf("\n\nPress a key to allocate another array.\n\n");
      _getch();
   }
}