#include <stdio.h>
#include <stdlib.h>

struct President
{
    char name[100];
    char party[50];
};
typedef struct President President;

struct City
{
    char name[100];
    int population;
};
typedef struct City City;

struct Country
{
    char name[50];
    President president;
    City capital;
    int population;
};
typedef struct Country Country;

void Read_City(City *c)
{
    printf("Enter name of City: ");
    scanf("%s", c->name);
    printf("Enter City Population: ");
    scanf("%d", &c->population);
}

void Print_City(City c)
{
    printf(" %s\nCity Population: %d\n", c.name, c.population);
}

void Read_President(President *p)
{
    printf("Enter name of President: ");
    scanf("%s", p->name);
    printf("Enter name of Political Party the president associates with: ");
    scanf("%s", p->party);
}

void Print_President(President p)
{
    printf("Name of president: %s\nName of party: %s\n", p.name, p.party);
}

void Read_Country(Country *c)
{
    printf("Enter name of country: ");
    scanf("%s", c->name);
    Read_President(&c->president); //& sign to get the memory of that address
    Read_City(&c->capital);
    printf("Enter Total population of the country: ");
    scanf("%d", &c->population);
}

void Print_Country(Country c)
{
    printf("Country: %s\n", c.name);
    Print_President(c.president);
    printf("Capital City is: ");
    Print_City(c.capital);
    printf("Total Population: %d", c.population);
}

int main()
{
    Country count;

    Read_Country(&count);
    Print_Country(count);

    return 0;
}
