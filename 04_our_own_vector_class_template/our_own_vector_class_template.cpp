#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template <class T>
class hke_vector {

private:
   T* ptr_data;
   int  counter;


public:
   hke_vector() {
      ptr_data = nullptr;
      counter = 0;
   }

   void push_back(T number) {

      if (counter == 0) {
         // Allocate memory in order to store the
         // first number
         ptr_data = (T*)malloc(1 * sizeof(T));
         ptr_data[0] = number;
         counter = 1;
      }
      else {
         ptr_data = (T*)realloc(ptr_data, (counter + 1) * sizeof(T));
         ptr_data[counter] = number;
         counter++;
      }
   }

   int size() { return counter; }

   T get_element(int idx) { return ptr_data[idx]; }

   void delete_element(int idx) {

      // 1. Rearrange elements
      for (int i = idx; i < size() - 1; i++) {
         ptr_data[i] = ptr_data[i + 1];
      }

      // 2. Make the memory block smaller
      counter--; // one element less!
      ptr_data = (T*)realloc(ptr_data, counter * sizeof(T));
   }

};

int main() {
   hke_vector<double> v;
   v.push_back(12.3);
   v.push_back(14.4);
   v.push_back(-7.3);
   v.push_back(-17.43);
   v.push_back(-37.54);

   for (int i = 0; i < v.size(); i++)
      std::cout << "Naechstes Element ist " << v.get_element(i) << "\n";

   v.delete_element(2);

   printf("After deleting:\n");
   for (int i = 0; i < v.size(); i++)
      std::cout << "Naechstes Element ist " << v.get_element(i) << "\n";
}