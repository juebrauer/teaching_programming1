#include <stdio.h>
#include <stdlib.h>

class hke_vector {

private:
   int* ptr_data;
   int  counter;


public:
   hke_vector() {
      ptr_data = nullptr;
      counter = 0;
   }

   void push_back(int number) {

      if (counter==0) {
         // Allocate memory in order to store the
         // first number
         ptr_data = (int*)malloc(1 * sizeof(int));
         ptr_data[0] = number;
         counter = 1;
      }
      else {
         ptr_data = (int*) realloc(ptr_data, (counter + 1) * sizeof(int));
         ptr_data[counter] = number;
         counter++;
      }
   }

   int size() { return counter; }

   int get_element(int idx) { return ptr_data[idx]; }

   void delete_element(int idx) {

      // 1. Rearrange elements
      for (int i=idx; i<size()-1; i++) {
         ptr_data[i] = ptr_data[i+1];
      }

      // 2. Make the memory block smaller
      counter--; // one element less!
      ptr_data = (int*) realloc(ptr_data, counter * sizeof(int));
   }

};

int main() {
   hke_vector v;
   v.push_back(12);
   v.push_back(14);
   v.push_back(-7);
   v.push_back(-17);
   v.push_back(-37);

   for (int i = 0; i < v.size(); i++)
      printf("Naechstes Element ist %d\n", v.get_element(i));

   v.delete_element( 2 );

   printf("After deleting:\n");
   for (int i = 0; i < v.size(); i++)
      printf("Naechstes Element ist %d\n", v.get_element(i));
}