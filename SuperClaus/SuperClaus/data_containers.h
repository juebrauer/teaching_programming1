#pragma once

template<typename T>
class myvector
{
public:
    myvector()
    {
        nr_elements = 0;
        capacity = 5;
        arr = (T*)malloc(capacity * sizeof(T));
    }

    void push_back(T element)
    {
        arr[nr_elements] = element;
        nr_elements++;
        check_enlarge();
    }

    int size()
    {
        return nr_elements;
    }

    T get_element(int i)
    {
        if ((i < 0) || (i >= nr_elements))
        {
            printf("Error!");
            _getch();
        }
        return arr[i];
    }

    void check_enlarge()
    {
        if (nr_elements == capacity)
        {
            printf("I need to enlarge the array!\n");
            capacity += 5;
            arr = (T*)realloc(arr, capacity * sizeof(T));
        }
    }

    void insert(int el, int pos)
    {
        if (pos <= nr_elements)
        {

            nr_elements++;
            check_enlarge();

            // make space for inserting the new
            // element <el>
            for (int i = nr_elements - 1; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }

            arr[pos] = el;
        }
    }

    void show_type()
    {
        printf("Data type stored in this vector is %s\n",
            typeid(T).name());
    }

    T& operator[](int idx)
    {
        return arr[idx];
    }

private:
    int  nr_elements;
    int  capacity;
    T*   arr;
};
