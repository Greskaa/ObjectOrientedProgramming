#include <iostream>
#include <cstring>

using namespace std;

class Worker
{
private:
    char firstName[30];
    char lastName[30];
    int salary;
public:
    //2 in 1 Constructor
    Worker(char *name="", char *surname="", int salary=0)
    {
        strcpy(this->firstName, name);
        strcpy(this->lastName, surname);
        this->salary = salary;
    }

    int getSalary()
    {
        return  salary;
    }

    void print()
    {
        cout<<firstName<<" "<<lastName<<" "<<salary<<endl;
    }
};

class Factory
{
private:
    int workersNumber;
    Worker workers[100];
public:
    //Constructor with arguments
    Factory(int workersNumber, Worker *workers)
    {
        this->workersNumber = workersNumber;
        for(int i=0; i<workersNumber; i++)
        {
            this->workers[i] = workers[i];
        }
    }

    //All workers
    void printWorkers()
    {
        for (int i=0; i<workersNumber; i++)
        {
            workers[i].print();
        }
    }

    //Depending on salary
    void printWithSalary(int salary)
    {
        for (int i=0; i<workersNumber; i++)
        {
            if (workers[i].getSalary() > salary)
            {
                workers[i].print();
            }
        }
    }
};

int main()
{
    int n;
    cin>>n;

    Worker *workers = new Worker[n];

    //Print All Workers
    cout<<"ALL WORKERS: "<<endl;
    for (int i=0; i<n; i++)
    {
        char firstName[30];
        char lastName[30];
        int salary;
        cin>>firstName>>lastName>>salary;
        workers[i] = Worker(firstName, lastName, salary);
    }

    int minSalary;
    cin>>minSalary;

    //Print based on salary
    Factory fact(n, workers);
    fact.printWorkers();
    cout<<"EMPLOYEES WITH SALARY "<<minSalary<<":"<<endl;
    fact.printWithSalary(minSalary);

    return 0;
}
