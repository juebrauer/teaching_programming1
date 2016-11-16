#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_NR_OF_PIZZAS_YOU_CAN_ORDER 10

enum pizza_types { Margherita, Salami, Funghi, Hawai, NR_PIZZA_TYPES };
enum pizza_sizes { S, M, L, XL, XXL, PartySize, NR_PIZZA_SIZES };

struct single_pizza_order {
   enum pizza_types   which_pizza;
   enum pizza_sizes   which_size;
};

struct single_pizza_order  all_pizza_orders[MAX_NR_OF_PIZZAS_YOU_CAN_ORDER];

char* pizza_type_names[]        = {"Pizza Margherita", "Salami Classico", "Funghi", "Hawaiian Dream"};
char* pizza_size_descriptions[] = { "Small", "Medium", "Large", "Extra Large", "XXL", "Party size" };


int nr_pizzas_ordered;


enum pizza_types choose_pizza_type()
{
   // 1. show available pizza sizes
   printf("\nAvailable pizza types:\n");
   for (int t = 0; t < NR_PIZZA_TYPES; t++)
   {
      printf("\t%d : %s\n", t, pizza_type_names[t]);
   }

   // 2. ask user to enter pizza type number till input is valid
   int desired_type;
   do
   {
      printf("\nYour choice: ");
      scanf_s("%d", &desired_type);
      if (!((desired_type >= 0) && (desired_type < NR_PIZZA_TYPES)))
      {
         printf("There is no pizza type with number %d\n", desired_type);
         printf("Please enter a number between %d and %d!\n", Margherita, Hawai);
      }

   } while (!((desired_type >= 0) && (desired_type < NR_PIZZA_TYPES)));

   return desired_type;

} // choose_pizza_type



enum pizza_types choose_pizza_size()
{
   printf("\nAvailable pizza sizes:\n");

   // 1. show available pizza sizes
   for (int s = 0; s < NR_PIZZA_SIZES; s++)
   {
      printf("\tsize %d : %s\n", s, pizza_size_descriptions[s]);
   }

   // 2. ask user to enter pizza size number till input is valid
   int desired_size;
   do
   {
      printf("\nYour desired size: ");
      scanf_s("%d", &desired_size);
      if (!((desired_size >= 0) && (desired_size < NR_PIZZA_SIZES)))
      {
         printf("There is no pizza size with number %d\n", desired_size);
         printf("Please enter a number between %d and %d!\n", S, PartySize);
      }

   } while (!((desired_size >= 0) && (desired_size < NR_PIZZA_SIZES)));

   return desired_size;

} // choose_pizza_size


void show_order_list()
{
   system("cls");

   printf("Here is your complete order:\n\n");

   for (int i = 0; i < nr_pizzas_ordered; i++)
   {
      enum pizza_types t = all_pizza_orders[i].which_pizza;
      enum pizza_sizes s = all_pizza_orders[i].which_size;
      printf("Pizza #%d: %s (%s)\n", i, pizza_type_names[t], pizza_size_descriptions[s] );
   }

} // show_order_list


int main()
{
   // 1. show welcome message
   printf("Hello! Welcome to UASKPS! - University of Applied Sciences Kempten Pizza service!\n");
   printf("You can order up to %d pizzas.\n\n", MAX_NR_OF_PIZZAS_YOU_CAN_ORDER);
   printf("\nPress any key to start your order.\n");
   _getch();

   // 2. let user order a single pizza in each loop run
   char c;
   nr_pizzas_ordered = 0;
   do
   {
      system("cls");

      // 2.1 show pizza number
      printf("\nPlease choose your pizza #%d\n", nr_pizzas_ordered+1);

      // 2.2 let user choose pizza type
      enum pizza_types desired_type = choose_pizza_type();

      // 2.3 let user choose pizza size
      enum pizza_sizes desired_size = choose_pizza_size();

      // 2.4 store the order
      all_pizza_orders[nr_pizzas_ordered].which_pizza = desired_type;
      all_pizza_orders[nr_pizzas_ordered].which_size  = desired_size;

      // 2.5 one pizza has been ordered more
      nr_pizzas_ordered++;
      
      // 2.6 ask user whether he wants to order another pizza
      if (nr_pizzas_ordered < MAX_NR_OF_PIZZAS_YOU_CAN_ORDER)
      {
         printf("Do you want to order another pizza? (y/n)");
         c = _getch();
      }
      else
         c = 'n';

   } while (c=='y');

   // 3. show order list
   show_order_list();

   // 4. That's it! We are ready for backing pizza!
   printf("\n\nThank you for your order! Press any key to exit.\n");
   _getch();
   
} // main