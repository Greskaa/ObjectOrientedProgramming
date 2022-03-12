#include <iostream>
#include <string.h>

using namespace std;

enum Position
{
    owner,
    manager,
    employee
};

class Employee
{
//attributes
private:
    char name[50];
    int salary;
    Position position;

public:
    Employee(char *_name="Gresa", int _salary = 15000, Position _position = manager)
    {
        strcpy(name, _name);
        salary = _salary;
        position = _position;
    }

    //method for printing the employee information
    void Print_Employee()
    {
        cout<<"Employee: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"Position: ";
        if (position == 0)
            cout<<"employee\n";
        else if (position == 1)
            cout<<"manager\n";
        else
            cout<<"owner\n";
    }

};

int main()
{
    int n;
    cout<<"Enter number of employees in the company: ";
    cin>>n;
    Employee employees_array[50];
    char name[50];
    int salary;
    int position;

    for (int i=0; i<n; i++)
    {
        cout<<"Enter name of employee: "; cin>>name;
        cout<<"Enter salary of employee: "; cin>>salary;
        cout<<"Enter position in the company: "; cin>>position;
        employees_array[i] = Employee(name, salary, Position(position));
    }

    for (int i=0; i<n; i++)
    {
        employees_array[i].Print_Employee();
    }

    return 0;
}
