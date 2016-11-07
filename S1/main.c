#include <stdio.h>  // for the printf(), scanf() command
#include <conio.h>  // for the _getch() command
#include <stdlib.h> // for rand()

int main()
{
   printf("\nSimple calculator:");
   printf("\nValid inputs are + - * /  = and digits 0,...,9");

   double r = 0.0;
   double digit = 0.0;
   char last_operator = '+';
   const int NEXT_INPUT_DIGIT_PLEASE = 1;
   const int NEXT_INPUT_OPERATOR_PLEASE = 2;
   int next_input = NEXT_INPUT_DIGIT_PLEASE;
      

   printf("\n\nYour input:\n");
   while (1)
   {
      char c = _getch();
            
      switch (c)
      {
         // if an operator is entered,
         // store the information about this operator
         // so that we can use it till the next number is entered
         case '+': 
         case '-': 
         case '*': 
         case '/':
            if (next_input != NEXT_INPUT_OPERATOR_PLEASE)
            {
               printf("\a");
               break;
            }
            printf("%c ", c);
            last_operator = c;            
            next_input = NEXT_INPUT_DIGIT_PLEASE;
            break;

         // user wants to output current intermediate result
         case '=':
            if (next_input != NEXT_INPUT_OPERATOR_PLEASE)
            {
               printf("\a");
               break;
            }
            printf("\n= %.2f ",r);
            next_input = NEXT_INPUT_OPERATOR_PLEASE;
            break;

         // user enters a digit
         case '0':
         case '1':
         case '2':
         case '3':
         case '4':
         case '5':
         case '6':
         case '7':
         case '8':
         case '9':         
            if (next_input != NEXT_INPUT_DIGIT_PLEASE)
            {
               printf("\a");
               break;
            }
            printf("%c ", c);
            digit=c-48;
            switch (last_operator)
            {
               case '+': r += digit; break;
               case '-': r -= digit; break;
               case '*': r *= digit; break;
               case '/': r /= digit; break;

            } // switch (last_operator)
            next_input = NEXT_INPUT_OPERATOR_PLEASE;
            break;

      } // switch (input character)

   } // while forever

   printf("\n\nGood bye!\n");
   printf("Press any key to exit this program.");
   _getch();
}
