#include <iostream>

using namespace std;

struct Employee
{
    //properties
    char name[100];
    double salary;

    //function inside the structure
    void Print_Employee()
    {
        cout<<"Employee: "<<name<<endl<<"Salary: "<<salary<<endl;
    }
};

//Function for creation of Employee read from SI
//Returning the information
Employee Create_Employee()
{
    Employee e1;
    cin>>e1.name;
    cout<<"Enter Salary of Employee: ";
    cin>>e1.salary;

    return e1;
}

struct Company
{
    char name[100];
    Employee manager;
    Employee employees[100];
    int total_employees;

    void Print_Company()
    {
        cout<<"Company: "<<name<<endl;
        cout<<"(Manager) ";
        manager.Print_Employee();
        cout<<endl;
        //Print all employees with a for loop
        for (int i=0; i<total_employees; i++)
        {
            employees[i].Print_Employee();
        }
    }
};

//Function for creation of a company
Company Create_Company()
{
    Company c1{}; //create an empty company with no data in it
    cout<<"Enter Name of Company: ";
    cin>>c1.name;

    c1.manager = Create_Employee(); //create an employee (name + salary) which is going to be set in the manager

    cout<<"Enter total number of employees working in the company: ";
    cin>>c1.total_employees;

    cout<<"Enter information about all employees: "<<endl;
    for (int i=0; i < c1.total_employees; i++)
    {
        cout<<"Enter Employee "<<i+1<<":";
        c1.employees[i] = Create_Employee();
    }

    return c1; //return all the information
}

int main()
{
    Company c1 = Create_Company();
    c1.Print_Company();

    return 0;
}
