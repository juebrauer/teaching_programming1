#include <iostream>
#include <vector>


// Template function
template<class T>
T foo(T a, T b, T c)
{
    return (a+b+c)/3;
}



int main()
{
    std::vector<int> vector_int;
    std::vector<float*> vector_float_pointer;

    

    std::vector< std::vector<int>* > vector_of_vector_pointer;

    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(22);

    std::vector<int> v2;
    v1.push_back(30);
    v1.push_back(10);
    v1.push_back(15);

    vector_of_vector_pointer.push_back( &v1 );
    vector_of_vector_pointer.push_back( &v2 );

    std::cout << "mittelwert = " << foo(10.2f,20.3f,5.1f) << "\n";

    std::cout << "mittelwert = " << foo(10,20,5) << "\n";
    
}