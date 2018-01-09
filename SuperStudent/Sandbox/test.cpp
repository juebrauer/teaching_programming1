#include <conio.h>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;


void example_usage_vector()
{
    // 1. declare a vector of random numbers
    vector<int> rnd_numbers;


    // 2. put some values into the vector
    for (int i = 1; i <= 5; i++)
    {
        rnd_numbers.push_back( 1 + rand() % 100 );
    }


    // 3.1 variant #1 to run over all elements
    printf("Here are all elements currently "
           "stored in rnd_numbers:\n");
    for (int i = 0; i < rnd_numbers.size(); i++)
    {
        printf("Element %d: %d\n", i, rnd_numbers[i]);
    }


    // 3.2 variant #2 to run over all elements
    printf("Here are once again all elements currently "
           "stored in rnd_numbers:\n");
    // declare an iterator to a vector of strings
    vector<int>::iterator it; 
    int i = 0;
    for (it = rnd_numbers.begin(); it != rnd_numbers.end(); it++, i++)
    {
        printf("Element %d: %d\n", i, *it);
    }


    // 3.3 variant #3: since C++11 we can use "auto"
    //     in order to avoid specifying a very long,
    //     complicated type name of the iterator as
    //     seen before
    printf("Here are once again all elements currently "
        "stored in rnd_numbers:\n");
    i = 0;
    for (auto it = rnd_numbers.begin(); it != rnd_numbers.end(); it++, i++) {
        printf("Element %d: %d\n", i, *it);
    }    


    // 4. delete 3rd element
    rnd_numbers.erase(rnd_numbers.begin() + 2);
    printf("After deleting 3rd element:\n");
    for (int i = 0; i < rnd_numbers.size(); i++)
    {
        printf("Element %d: %d\n", i, rnd_numbers[i]);
    }


    // 5.1 insert an element before 3rd element
    rnd_numbers.insert(rnd_numbers.begin()+2, 1111);
    printf("After inserting some element:\n");
    for (int i = 0; i < rnd_numbers.size(); i++)
    {
        printf("Element %d: %d\n", i, rnd_numbers[i]);
    }


    // 5.2 insert several elements before 3rd element
    int array2insert[] = { 501,502,503 };
    rnd_numbers.insert(rnd_numbers.begin() + 2, array2insert, array2insert+1);
    printf("After inserting several elements:\n");
    for (int i = 0; i < rnd_numbers.size(); i++)
    {
        printf("Element %d: %d\n", i, rnd_numbers[i]);
    }


} // example_usage_vector


void example_usage_set()
{
    // 1. declaring a set
    set<int> s;


    // 2. inserting elements into a set    
    s.insert(10);
    s.insert(5);
    s.insert(2);


    // 3. running through the elements of a set
    //    [] access operator does not exist for sets!
    //    we have to use an iterator
    int i = 0;
    for (auto it = s.begin(); it != s.end(); it++, i++) {
        printf("Element %d: %d\n", i, *it);
    }


    // 4. searching in a set
    set<int>::iterator it;
    it = s.find(5);
    if (it != s.end())
        printf("Found number '5' in the set!\n");
    else
        printf("Could not find number '5' in the set!\n");
    it = s.find(17);
    if (it != s.end())
        printf("Found number '17' in the set!\n");
    else
        printf("Could not find number '17' in the set!\n");


    // 5. sets of strings are also possible
    set<string> s2;
    printf("\n\nSubjects:\n");
    s2.insert("Zoologie");
    s2.insert("Informatik");    
    s2.insert("Elektrotechnik");
    s2.insert("Maschinenbau");
    i = 0;
    for (auto it = s2.begin(); it != s2.end(); it++, i++) {
        printf("Element %d: %s\n", i, (*it).c_str());
    }


    // 6. removing an element from a set
    printf("Subjects after erasing:\n");
    s2.erase("Informatik");
    i = 0;
    for (auto it = s2.begin(); it != s2.end(); it++, i++) {
        printf("Element %d: %s\n", i, (*it).c_str());
    }
    
} // example_usage_set



void example_usage_map()
{
    // 1. how to declare a map
    map<string, int> m;
    map<string, vector<int>> m2;


    // 2. how to insert values into a map
    m["Informatik"] = 600;
    m["Elektrotechnik"] = 800;
    m["Maschinenbau"] = 1200;


    // 3. how to iterate over a map
    map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        printf("%s --> %d\n", it->first.c_str(), it->second);
        it++;
    }


    // 4. how to use map entries
    int sum = m["Informatik"] + m["Elektrotechnik"] + m["Maschinenbau"];


    // 5. how to search for a key
    if (m.find("Tourismus") == m.end())
        printf("Study course 'Tourismus' not found!\n");

} // example_usage_map


class Logger
{
public:
    virtual void logmsg(string s) = 0;
    virtual void logmsg2(string s) = 0;
};

class LoggerConsole : public Logger
{
public:
    void logmsg(string s)
    {
        printf("writting logmsg to console\n");
    }

    void logmsg2(string s)
    {
        printf("writting logmsg to console\n");
    }
};

class LoggerFile : public Logger
{
    void logmsg(string s)
    {
        printf("writting logmsg to file\n");
    }
};


int main()
{

    Logger* l = new LoggerConsole();
    l->logmsg("Program started.\n");


    example_usage_vector();

    //example_usage_set();

    //example_usage_map();

    _getch();
}