#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char *content;

    //Copy Method
    void copy(const String &other)
    {
        this->content = new char[strlen(other.content) + 1];
        strcpy(this->content, other.content);
    }

public:
    //Predefined Constructor with default values
    String(char *content="")
    {
        this->content = new char[strlen(content) + 1];
        strcpy(this->content, content);
    }

    //Copy Constructor
    String(const String &other)
    {
        copy(other); //copy method will only be called  after the deletion of the already allocated memory
    }

    //Overload the operator =
    String& operator=(const String &other)
    {
        if (this!=&other) //it prevents self-assignment -> checks if my(this)-address is different from the other-address
        {
            delete []content;
            copy (other);
        }
        return *this; //We need the content of my (this) string
    }

    //Destructor
    ~String()
    {
        delete []content; //clears the dynamically allocated memory of "content"
    }

    void print()
    {
        cout<<content<<endl;
    }
};

int main()
{
    String s1("Gresa");
    String s2;
    s2 = s1; //put the content of object s1 into object s2 using = operator

    s2.print();
    return 0;
}
