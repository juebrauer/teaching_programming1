/// file: O4.cpp
///
/// solution for exercise comparing references and pointers
///
/// see also:
/// http://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in
///
/// ---
/// Prof. Dr. Jürgen Brauer, www.juergenbrauer.org
///

#include <stdio.h>  // for printf()
#include <conio.h>  // for getch()

class A
{
   public:
      A(int value)
      {
         this->value = value;
      }

      int get_value()
      {
         return value;
      }

      void set_value(int value)
      {
         this->value = value;
      }

   private:
      int value;
};

int main()
{
   // 1. pointers and references can be used to point to
   //    variables
   int i=42;
   int* pi = &i;
   int& ri = i;
   i = 43;
   printf("value of i according to pointer   : %d\n", *pi);
   printf("value of i according to reference : %d\n", ri);
   printf("\n");

   // 2. pointers and references can be used to point to
   //    objects
   A O1(17);
   A* pobj = &O1;
   A& robj = O1;
   printf("value of O1 according to pointer   : %d\n", pobj->get_value());
   printf("value of O1 according to reference : %d\n", O1.get_value());
   printf("\n");


   // 3. pointers can be reassigned to another variable/object
   //    but references not!
   A O2(101);
   pobj = &O2; // reassign pointer <pobj> to new object <O2>
   robj = O2;  // reassign reference <robj> to new object <O2> ???
   printf("value of O2 according to pointer   : %d\n", pobj->get_value());
   printf("value of O2 according to reference : %d\n", robj.get_value());
   printf("\n");

   O2.set_value(202);
   printf("value of O2 according to pointer   : %d\n", pobj->get_value());
   // we will not see 202 outputted by the following line,
   // because above we did not reassign the reference, but copied the value
   // of O2 to O1!
   printf("value of O2 according to reference robj : %d\n", robj.get_value());
   printf("value of O2: %d\n", O2.get_value());
   printf("value of O1: %d\n", O1.get_value());
   printf("\n");


   // 4. with pointers we can do "pointer arithmetic"
   //    but there is no "reference arithmetic"
   int* SomeArray = new int[1000];
   SomeArray[0] = 21;
   SomeArray[5] = 422;

   int* ptr = SomeArray;
   ptr = ptr + 5;
   printf("ptr points to variable with value = %d\n", *ptr);
      
   int& ref = *SomeArray;
   ref = ref + 5;
   printf("ref references variable with value = %d\n", ref);
   printf("\n");


   // conclusion:
   // references are something like constant pointers which automatic
   // indirection, i.e. the compiler does the dereferencing * for us

   // note:
   // a reference is not the same as the object itself!
   // there is a interesting discussion about this here:
   // https://stackoverflow.com/questions/3224155/c-difference-between-reference-objects-and-pointers
   // with the final conclusion:
   // 
   //  "A reference is essentially a synonym for another object.
   //   Internally, it is often implemented as a pointer, but it has the
   //   syntax as if it were the object it refers to.
   // 
   //   A pointer is a separate object that stores the memory address
   //   of the object it points to (or 0 if it doesn't point to an object).
   //
   //   You could say that the reference is the object that it refers to
   //   (it certainly acts that way), but it is not.
   //   If a reference goes out of scope then the object it refers to is
   //   not destructed, so the reference is not the object."
   //
   // and another quote from that discussion:
   //
   //  "A reference is syntactic sugar for a const pointer.
   //   Just like a const pointer, it must be bound to an lvalue at
   //   initialization, and can never be rebound."
   
   _getch();
}