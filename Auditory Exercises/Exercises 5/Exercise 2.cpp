#include <iostream>
#include <cstring>

using namespace std;

class Team
{
private:
    char *name;
    char *city;
    char *stadium;

    //Copy Method
    void copy(const Team &t)
    {
        this->name = new char [strlen(t.name)+1];
        strcpy(this->name, t.name);
        this->city = new char [strlen(t.city)+1];
        strcpy(this->city, t.city);
        this->stadium = new char [strlen(t.stadium)+1];
        strcpy(this->stadium, t.stadium);
    }

public:
    //Default Constructor with predefined values
    Team(char *name="", char *city="", char *stadium="")
    {
        this->name = new char [strlen(name)+1];
        strcpy(this->name, name);
        this->city = new char [strlen(city)+1];
        strcpy(this->city, city);
        this->stadium = new char [strlen(stadium)+1];
        strcpy(this->stadium, stadium);
    }

    //Copy Constructor
    Team(const Team &t)
    {
        copy(t);
    }

    //Overload operator =
    Team& operator=(const Team &t)
    {
        if (this != &t)
        {
            delete []name;
            delete []city;
            delete []stadium;
            copy(t);
        }
        return *this;
    }

    //Destructor
    ~Team()
    {
        delete []name;
        delete []city;
        delete []stadium;
    }

    //Print Team
    void Print_Team()
    {
        cout<<"Team name: "<<name<<endl;
        cout<<"City of the team: "<<city<<endl;
        cout<<"Stadium where the team will match: "<<stadium<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter total number of teams: "; cin>>n;

    //Declare array of team objects
    Team *teams = new Team[n]; //Class the default constructor in the class n-times

    char name[100];
    char city[100];
    char stadium[100];

    //Get info for the teams array
    for (int i=0; i<n; i++)
    {
        cout<<"Enter name of the team: "; cin>>name;
        cout<<"Enter name of the city: "; cin>>city;
        cout<<"Enter name of the stadium: "; cin>>stadium;

        teams[i] = Team(name, city, stadium);
    }

    //Print the teams array
    for (int i=0; i<n; i++)
    {
        teams[i].Print_Team();
    }

    return 0;
}
