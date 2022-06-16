#include <iostream>
#include <cstring>

using namespace std;

class Apartment
{
private:
    int numberApartments;
    int numberParkings;
    int numberEntrances;
    char *location;
public:
    //Default Constructor + Constructor with parameters
    Apartment(int numberApartments=0, int numberParkings=0, int numberEntrances=0, char *location="")
    {
        this->numberApartments = numberApartments;
        this->numberParkings = numberParkings;
        this->numberEntrances = numberEntrances;
        this->location = new char[strlen(location)+1];
        strcpy(this->location, location);
    }
    //Copy Constructor
    Apartment(const Apartment &a)
    {
        this->numberApartments = a.numberApartments;
        this->numberParkings = a.numberParkings;
        this->numberEntrances = a.numberEntrances;
        this->location = new char[strlen(a.location)+1];
        strcpy(this->location, a.location);
    }
    //Assignment Operator Overloading
    Apartment & operator = (const Apartment &a)
    {
        if (this != &a)
        {
            delete []location;

            this->numberApartments = a.numberApartments;
            this->numberParkings = a.numberParkings;
            this->numberEntrances = a.numberEntrances;
            this->location = new char[strlen(a.location)+1];
            strcpy(this->location, a.location);
        }
        return *this;
    }
    //Destructor
    ~Apartment()
    {
        delete []location;
    }

    //Check if two apartments are the same
    bool operator == (const Apartment &a)
    {
        return strcmp(this->location, a.location)==0 && this->numberApartments == a.numberApartments;
    }

    //Check if one of the apartments is bigger than the other aprtments
    bool operator > (const Apartment &a)
    {
        return this->numberParkings > a.numberParkings; //if this>z -> returns true
    }

    //Check if <=
    bool operator <= (int numberEntrances)
    {
        return this->numberEntrances <= numberEntrances;
    }

    //returns reference of the class ostream (&)
    friend ostream& operator << (ostream &out, const Apartment &a) //const is needed because we just print the information
    {
        out<<"Location: "<<a.location<<" Number of entrances: "<<a.numberEntrances<<" Number of parking lots: "<<a.numberParkings<<" Number of apartments:"<<a.numberApartments<<endl;
        return out;
    }

    //return reference from the class istream (&)
    friend istream& operator >> (istream &in, Apartment &a) //const is not needed because we input information and "change it" (const keeps it the same)
    {
        cout<<"Enter location of Apartment: ";
        in>>a.location;
        cout<<"Enter number of apartments in total in the building: ";
        in>>a.numberApartments;
        cout<<"Enter number of parking in the building: ";
        in>>a.numberParkings;
        cout<<"Enter number of entrances in the building: ";
        in>>a.numberParkings;

        return in;
    }
    //Required Methods for this class
    void printApartment()
    {
        cout<<"The Apartments' location is: "<<location<<endl;
        cout<<"The Building has a total of "<<numberApartments<<" apartments, "<<numberEntrances<<" entrances and "<<numberParkings<<" parking lots."<<endl;
    }
};

class Complex
{
private:
    int totalApartments;
    Apartment *apartments;
public:
    //Default Constructor + Constructor with parameters
    Complex(int totalApartments=0, Apartment *apartments=NULL)
    {
        this->totalApartments = totalApartments;
        this->apartments = new Apartment[totalApartments];
        for (int i=0; i<totalApartments; i++)
        {
            this->apartments[i] = apartments[i];
        }
    }
    //Copy Constructor
    Complex(const Complex &c)
    {
        this->totalApartments = c.totalApartments;
        this->apartments = new Apartment[c.totalApartments];
        for (int i=0; i<c.totalApartments; i++)
        {
            this->apartments[i] = c.apartments[i];
        }
    }
    //Assignment Operator Overloading
    Complex & operator = (const Complex &c)
    {
        if (this != &c)
        {
            delete []apartments;

            this->totalApartments = c.totalApartments;
            this->apartments = new Apartment[c.totalApartments];
            for (int i=0; i<c.totalApartments; i++)
            {
                this->apartments[i] = c.apartments[i];
            }
        }
        return *this;
    }
    //Destructor
    ~Complex()
    {
        delete []apartments;
    }

    //Operators
    Complex operator += (const Apartment &addApartment)
    {

        Apartment *temporary = new Apartment[totalApartments + 1]; //adds another element in the dynamically allocated memory (with the help of temp array)

        for (int i=0; i<totalApartments; i++)
        {
            temporary[i] = apartments[i];
        }
        temporary[totalApartments] = addApartment;

        delete []apartments; //free memory from apartments array
        apartments = temporary; //point to the temporary array in the memory
        totalApartments++; //increase the number of apartments by 1

        return *this;
    }

    //Ostream
    friend ostream & operator << (ostream &out, const Complex &c)
    {
        cout<<"The complex has a total of: "<<c.totalApartments<<" total apartments"<<endl;
        for (int i=0; i<c.totalApartments; i++)
        {
            cout<<c.apartments[i]<<endl;
        }
        return out;
    }
};

int main()
{
    Apartment a1;
    cin>>a1;
    cout<<a1<<endl;

    Apartment a2;
    cin>>a2;
    cout<<a2<<endl;


    if (a1 == a2)
        cout<<"Same apartments"<<endl;

    if (a1 > a2)
        cout<<"First Apartment has more parking lots from Second Apartment"<<endl;

    if (a1 <= 10)
        cout<<"Apartment 1 has at least 10 entrances"<<endl;

    Complex c1;
    c1 += a1; //adds building a1 to the complex
    c1 += a2; //adds building a2 to the complex
    //if the += operator is not written in the class part then the CPU won't know how to add the buildings to the Complex
    //it should be defined in the class where it adds them (in this case: class Complex)
  
    return 0;
}
