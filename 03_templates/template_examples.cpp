#include <vector>
#include <iostream>

template <class T>
class A
{
private:
   std::vector<T> data;

public:
   void set_data(std::vector<T> new_data)
   {
      data = new_data;
   }

   void show_info()
   {
      for (int i = 0; i < data.size(); i++)
         std::cout << data[i] << " ";
      std::cout << "\n";
   }
   
};


template <class T>
T get_mean(T n1, T n2)
{
   return (n1 + n2) / 2;
}


int main()
{
   A<int> myA;
   std::vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(12);
   myA.set_data(v);
   myA.show_info();

   A<float> myA2;
   std::vector<float> v2;
   v2.push_back(1.2f);
   v2.push_back(2.43f);
   v2.push_back(430.43f);
   myA2.set_data(v2);
   myA2.show_info();

   std::cout << "mean:" << get_mean(1, 3) << "\n";
   std::cout << "mean:" << get_mean(1.43f, 2.3904f) << "\n";
}