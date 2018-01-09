#include <conio.h>
#include <vector>

class Subject
{

};

int main()
{
    std::vector<Subject*> v;

    Subject* s1 = new Subject();

    v.push_back(s1);
    v.push_back( new Subject() );
    v.push_back( new Subject() );

    for (int i = 0; i < v.size(); i++)
        printf("Element %d of vector v is %p\n", i, v[i]);

    _getch();
}