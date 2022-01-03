#include "employee.h"


employee::employee(std::string first_name, std::string family_name, double salary) :
         person(first_name, family_name)
{
    this->salary = salary;
}

double employee::get_salary()
{
    return salary;
}

void employee::do_something()
{
    std::cout << "I am generating exams ..." << std::endl;
}
