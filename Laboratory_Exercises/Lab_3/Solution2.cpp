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
        //Default Constructor
        Worker(){}
        //Constructor with arguments
        Worker(char *firstName, char *lastName, int salary)
        {
            strcpy(this->firstName, firstName);
            strcpy(this->lastName, lastName);
            this->salary = salary;
        }

        int getSalary()
        {
            return salary;
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
        Factory(int workersNumber, Worker *workers)
        {
            this->workersNumber = workersNumber;
            for (int i=0; i<workersNumber; i++)
            {
                this->workers[i] = workers[i];
            }
        }

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
        Worker workers[n];

        for (int i=0; i<n; i++)
        {
            char name[30];
            char surname[30];
            int salary;
            cin>>name>>surname>>salary;
            workers[i] = Worker(name, surname, salary);

        }

        cout<<"ALL WORKERS: "<<endl;
        for (int i=0; i<n; i++)
        {
            workers[i].print();
        }

        int minSalary;
        cin>>minSalary;

        Factory factory(n, workers);
        cout<<"EMPLOYEES WITH SALARY "<<minSalary<<":"<<endl;

        factory.printWithSalary(minSalary);

        return 0;
    }
