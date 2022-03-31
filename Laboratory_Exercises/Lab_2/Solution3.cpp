#include <iostream>
#include <cstring>

using namespace std;

class Film
{
private:
    char name[100];
    char director[50];
    char genre[50];
    int year;
public:
    //Default constructor with
    Film(){}

    //Parametrized Constructor
    Film(char *_name, char *_director, char *_genre, int _year)
    {
        strcpy(name, _name);
        strcpy(director, _director);
        strcpy(genre, _genre);
        year = _year;
    }

    //Print Method
    void Print_Film()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Director: "<<director<<endl;
        cout<<"Genre: "<<genre<<endl;
        cout<<"Year: "<<year<<endl;
    }

    int getYear()
    {
        return year;
    }

};

//External function
void print_by_year(Film *f, int n, int year)
{
    for (int i=0; i<n; i++)
    {
        if (f[i].getYear() == year)
            f[i].Print_Film();
    }
}

int main()
{
    //total films
    int n;
    cin>>n;

    Film films[n];

    char name[100];
    char director[50];
    char genre[50];
    int year;

    for (int i=0; i<n; i++)
    {
        cin>>name>>director>>genre>>year;
        films[i] = Film(name, director, genre, year);
    }

    int y;
    cin>>y;

    print_by_year(&films[0], n, y);


    return 0;
}
