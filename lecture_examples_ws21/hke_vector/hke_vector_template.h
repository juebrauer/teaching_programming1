
template<class T>
class hke_vector_template
{
    public:

    hke_vector_template()
    {
        count = 0;
        ptr_data = nullptr;
    }


    ~hke_vector_template()
    {
        std::cout << "Deleting memory for storing all the " << count << " numbers" << std::endl;
        free( ptr_data );
    }


    void add(T number)
    {
        if (count == 0)
        {
            // malloc
            ptr_data = (T*) malloc(1 * sizeof(T));
            ptr_data[0] = number;
            count = 1;
        }
        else
        {
            // realloc
            ptr_data = (T*) realloc(ptr_data, (count+1) * sizeof(T));

            ptr_data[count] = number;
            count++;
        }
    }


    unsigned int size()     
    {
        return count;
    }


    T get_element(int idx)
    {
        if ((idx<0) || (idx>=count))
        {
            std::cout << "Invalid index!\n";
            return 0;
        }
        return ptr_data[idx];
    }


    void delete_element(int idx)
    {
        // 1. Verschieben der Elemente
        for (int i=idx; i<count-1; i++)
        {
            ptr_data[i] = ptr_data[i+1];
        }

        // 2. Speicher kleiner machen
        count--;    
        ptr_data = (T*) realloc(ptr_data, count * sizeof(T));
    }


    private:

        int count;

        T* ptr_data;



};