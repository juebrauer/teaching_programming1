#include <stdio.h>

#include <iostream>
#include <string>

#include "person.h"
#include "employee.h"




class student : public person
{
   public:

      student(std::string first_name, std::string family_name, uint matricle_nr) :
         person(first_name, family_name)
      {
         this->matricle_nr = matricle_nr;
      }


      uint get_matricle_nr()
      {
         return matricle_nr;
      }

      bool set_matricle_nr(uint new_matricle_nr)
      {
         if ((new_matricle_nr == 0) || (new_matricle_nr > 1000000))
            return false;

         this->matricle_nr = new_matricle_nr;
         return true;
      }


      void augment_first_name()
      {
         //this->first_name = "Student " + this->first_name;
         this->set_first_name( "Student " + this->get_first_name() );
      }


   private:

      uint matricle_nr;

};


int main()
{
   employee e1("Juergen", "Brauer", 100);
   std::cout << "First name of this object is " << e1.get_first_name() << std::endl;
   std::cout << "Salary is " << e1.get_salary() << std::endl;


   student s1("Homer", "Simpson", 123456);
   std::cout << "First name of this object is " << s1.get_first_name() << std::endl;
   std::cout << "Matricle nr " << s1.get_matricle_nr() << std::endl;

   s1.set_matricle_nr(0);
   std::cout << "Matricle nr " << s1.get_matricle_nr() << std::endl;

   s1.set_matricle_nr(2000000000);
   std::cout << "Matricle nr " << s1.get_matricle_nr() << std::endl;

   bool b = s1.set_matricle_nr(999);
   if (b==true)
   {
      std::cout << "Hat funktioniert.\n";
   }
   else
   {
      std::cout << "Hat nicht funktioniert.\n";
   }
   std::cout << "Matricle nr " << s1.get_matricle_nr() << std::endl;

   s1.set_first_name("");

   s1.augment_first_name();
   std::cout << "First name of this object is " << s1.get_first_name() << std::endl;  
   
}

