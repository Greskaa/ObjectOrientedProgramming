#include <iostream>
#include <cstring>

using namespace std;

class Array
{
private:
    int size;
    int capacity;
    int *array;
public:
    //Default Constructor with arguments
    Array(int capacity=10)
    {
        size = 0;
        this->capacity = capacity;
        array = new int[capacity];
        for (int i=0; i<size; i++)
        {
            this->array[i] = array[i];
        }
    }
    //Copy Constructor
    Array(const Array &a)
    {
        this->size = a.size;
        this->capacity = a.capacity;
        this->array = new int[a.capacity];
        for (int i=0; i<a.size; i++)
        {
            this->array[i] = a.array[i];
        }
    }
    //Operator Overloading =
    Array & operator = (const Array &a)
    {
        if (this != &a)
        {
            delete []array;

            this->size = a.size;
            this->capacity = a.capacity;
            this->array = new int[a.capacity];
            for (int i=0; i<a.size; i++)
            {
                this->array[i] = a.array[i];
            }
        }
        return *this;
    }
    //Destructor
    ~Array()
    {
        delete []array;
    }

    //Methods required
    void add(int element)
    {
        if (size < element)
            array[size++] = element;
        else
        {
            int *temporary = new int [2*capacity]; //create a temporary array that will have twice the capacity of elements
            for (int i=0; i<size; i++)
            {
                temporary[i] = array[i]; //copy everything to the temporary array from the array we have
            }
            temporary[size++] = element; //add the last element
            delete []array;              //delete the previous memory;
            array = temporary;           //make the previous memory to point to the temp memory
            capacity = capacity*2;       //double the capacity
        }
    }

    void replaceAll(int a, int b)
    {
        for (int i=0; i<size; i++)
        {
            if (array[i] == a)
                array[i] == b;
        }
    }

    void deleteAll(int number)
    {
        int j=0;
        for (int i=0; i<size; i++)
        {
            if (array[i] != number)
                array[j++] = array[i]; //get the element from the array and put it in the position j
        }
        size = j;
    }

    void printArray()
    {
        cout<<"Capacity: "<<capacity<<endl;
        cout<<"Size: "<<size<<endl;
        cout<<"Percentage: "<<(100.0 * (size / *array))<<"%"<<endl;
        cout<<"Elements in the array: [";
        for(int i=0; i<size; i++)
        {
            if (i != size-1)
                cout<<array[i]<<", ";
            else
                cout<<array[i]<<"]";
        }
    }
};

int main()
{
    //Calling default constructor
    Array a;
    a.printArray();

    cout<<"---------------------"<<endl;
    for (int i=1; i<=9; i++)
    {
        a.add(i);
    }

    a.printArray();
    cout<<"---------------------"<<endl;

    a.add(1);
    a.add(2);

    a.printArray();
    //

    return 0;
}
