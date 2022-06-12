#include <iostream>
#include <cstring>

using namespace std;

class Table
{
private:
    int width;
    int height;
public:
    //Default Constructor
    Table(){}
    //Constructor with parameters
    Table(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    void print()
    {
        cout<<"Table: "<<height<<" "<<width<<endl;
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
    //Constructor with parameters
    Room(Table table, int length, int width)
    {
        this->table = table;
        this->length = length;
        this->width = width;
    }
    void print()
    {
        cout<<"Room: "<<length<<" "<<width<<" ";
        table.print();
    }
};

class House
{
private:
    Room room;
    char address[50];
public:
    //Default Constructor
    House(){}
    //Constructor with parameters
    House(Room room, char *address)
    {
        this->room = room;
        strcpy(this->address, address);
    }
    void print()
    {
        cout<<"Address: "<<address<<" ";
        room.print();
    }
};

int main()
{
    int n;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        int table_height, table_width;
        int room_length, room_width;
        char address[50];

        cin>>table_height>>table_width;
        cin>>room_length>>room_width;
        cin>>address;

        Table t(table_width, table_height);
        Room r(t, room_length, room_width);
        House h(r, address);

        h.print();
    }

    return 0;
}
