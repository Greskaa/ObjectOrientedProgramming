#include <iostream>
#include <cstring>

using namespace std;

class Team
{
private:
    char name[30];
    int founding_year;
    char city[30];
public:
    //2 in 1 constructor
    Team(char *_name="", int _founding_year=1900, char *_city="")
    {
        strcpy(name, _name);
        founding_year = _founding_year;
        strcpy(city, _city);
    }
    //Copy Constructor
    Team(const Team &t)
    {
        strcpy(name, t.name);
        founding_year = t.founding_year;
        strcpy(city, t.city);
    }
    //Destructor
    ~Team(){}

    //Print it
    void Print_Team()
    {
        cout<<"Team name: "<<name<<endl;
        cout<<"Team City: "<<city<<endl;
        cout<<"Team Foundation Year: ("<<founding_year<<")"<<endl;
    }
};

class Game
{
private:
    Team home_team;
    Team away_team;
    int home_goals;
    int away_goals;
public:
    //Default Constructor
    Game()
    {
        home_goals = 0;
        away_goals = 0;
    }

    //Parametrized Constructor
    Game (Team _home_team, Team _away_team, int _home_goals, int _away_goals)
    {
        home_team = _home_team;
        away_team = _away_team;
        home_goals = _home_goals;
        away_goals = _away_goals;
    }

    //Copy Constructor
    Game(const Game &g)
    {
        home_team = g.home_team;
        away_team = g.away_team;
        home_goals = g.home_goals;
        away_goals = g.away_goals;
    }

    //Destructor
    ~Game(){}

    //Print Game
    void Print_Game()
    {
        cout<<"Game between: "<<endl;
        home_team.Print_Team();
        cout<<" and ";
        away_team.Print_Team();
        cout<<endl<<"Result: "<<home_goals<<"- "<<away_goals;
    }
};

int main()
{
    //Create 2 Team objects
    Team t1("Barca", 1980, "Barcelona");
    Team t2("Real", 1978, "Madrid");

    //Define a game between Barca and Real
    Game game(t1, t2, 4, 3);

    //Print the Game Methods
    game.Print_Game();

    return 0;
}
