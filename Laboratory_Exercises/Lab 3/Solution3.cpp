#include <iostream>
#include <cstring>

using namespace std;

class Table
{
private:
    int width;
    int height;
public:
    //Default Constructor with predefined values
    Table(int width=0, int height=0)
    {
        this->width = width;
        this->height = height;
    }

    //Print Table
    void print()
    {
        cout<<"Table: "<<width<<" "<<height<<endl;
    }
};

class Room
{
private:
    Table table;
    int length;
    int width;
public:
    //Default Constructor
    Room(){}
    //Parametrized Constructor
    Room(int width, int length, Table &table)
    {
        this->width = width;
        this->length = length;
        this->table = table;
    }

    //Print Room
    void print()
    {
        cout<<"Room: "<<width<<" "<<length;
        cout<<" ";
        table.print();
    }
};

class House
{
private:
    Room room;
    char address[50];
public:
    //Default Constructor with predefined values
    House(Room &room, char *address)
    {
        this->room = room;
        strcpy(this->address, address);
    }

    //Print House
    void print()
    {
        cout<<"Address: "<<address;
        cout<<" ";
        room.print();
    }
};

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
    	int tableWidth, tableHeight;
        cin>>tableWidth;
        cin>>tableHeight;
    	Table t(tableWidth, tableHeight);

    	int rw, rl;
        cin>>rw;
        cin>>rl;
    	Room r(rw, rl, t);

    	char adresa[30];
        cin>>adresa;
    	House h(r,adresa);
    	h.print();
	}

    return 0;
}
