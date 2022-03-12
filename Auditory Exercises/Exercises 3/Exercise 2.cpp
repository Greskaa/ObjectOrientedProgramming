#include <iostream>
#include <math.h>

using namespace std;

class Triangle
{
private:
    //properties of class
    int a;
    int b;
    int c;

public:
    //Constructor for the class
    Triangle (int _a=1, int _b=1, int _c=1)
    {
        a = _a;
        b = _b;
        c = _c;
    }

    //Method for calculating the Perimeter
    float Perimeter()
    {
        return a+b+c;
    }
    //Method for calculating the Area
    float Area()
    {
        float s=(a+b+c)/2;
        return sqrt(s * (s-a) * (s-b) * (s-c));
    }

    void Print_Triangle()
    {
        cout<<"A: ";
        for (int i=0; i<a; i++) cout<<"-";
        cout<<endl;
        cout<<"B: ";
        for (int i=0; i<b; i++) cout<<"-";
        cout<<endl;
        cout<<"C: ";
        for (int i=0; i<c; i++) cout<<"-";
        cout<<endl<<endl;

        cout<<"Perimeter of triangle: "<<Perimeter()<<endl;
        cout<<"Area of triangle: "<<Area()<<endl;
    }

    ~Triangle()
    {
        //delete the not used objects
    }
};

int main()
{
    int a, b, c;
    cout<<"Enter a: "; cin>>a;
    cout<<"Enter b: "; cin>>b;
    cout<<"Enter c: "; cin>>c;
    Triangle t1(a, b, c);
    t1.Print_Triangle();

    return 0;
}
