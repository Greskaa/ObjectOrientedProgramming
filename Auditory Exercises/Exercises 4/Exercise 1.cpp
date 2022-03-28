#include <iostream>
#include <cstring>

using namespace std;

enum Gender
{
    male, //0
    female, //1
    other //2
};

class Mate
{
private:
    char name[30];
    int age;
    Gender gender;
public:
    //Default Constructor
    Mate()
    {
        strcpy(name, "");
        age = 1;
        gender = male;
    }

    //Parametrized Constructor
    Mate(char *_name, int _age, Gender _gender)
    {
        strcpy(name, _name);
        age = _age;
        gender = _gender;
    }

    //Copy Constructor
    Mate(const Mate &otherMate)
    {
        strcpy(name, otherMate.name);
        age = otherMate.age;
        gender = otherMate.gender;
    }

    void Print_Gender()
    {
        if (gender==0) cout<<"male";
        else if (gender==1) cout<<"female";
        else cout<<"other";
    }

    void Print_Mate()
    {
        cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl<<"Gender: ";
        Print_Gender();
        cout<<endl;
    }

    int getAge()
    {
        return age;
    }

    //Destructor
    ~Mate(){}
};

class Date
{
private:
    Mate mate1;
    Mate mate2;
public:
    //Default Constructor
    Date(){}

    //Parametrized Constructor
    Date(Mate _mate1, Mate _mate2)
    {
        mate1 = _mate1;
        mate2 = _mate2;
    }

    //Copy Constructor
    Date(const Date &otherMate)
    {
        mate1 = otherMate.mate1;
        mate2 = otherMate.mate2;
    }

    void Print_Date()
    {
        cout<<"Date between: "<<endl;
        mate1.Print_Mate();
        cout<<endl<<"and"<<endl<<endl;
        mate2.Print_Mate();
        cout<<isSuccess() ? "Successful" : "Not Successful";
    }

    bool isSuccess()
    {
        int difference = abs(mate1.getAge() - mate2.getAge());

        return difference > 2 && difference <= 5; //no need for if-else statement
    }

    //Destructor
    ~Date(){}
};

int main()
{
    //Instantiate objects
    Mate m1("Brad Pitt", 35, male);
    Mate m2("Angelina Jolie", 32, female);

    Date date(m1, m2); //call date for m1 and m2

    date.Print_Date();

    return 0;
}
