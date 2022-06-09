#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Triangle
{
private:
    float a, b, c;
public:
    //Def Constructor
    Triangle(float _a, float _b, float _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }

    //Method for calculating perimeter of the triangle
    float Perimeter()
    {
        return a + b + c;
    }

    //Method for calculating area of the triangle
    float Area()
    {
        float s = (a + b + c)/2;
        return sqrt(s * (s-a) * (s-b) * (s-c));
    }
};

int main()
{
    float a, b, c;
    cout<<"Enter first length: ";
    cin>>a;
    cout<<"Enter second length: ";
    cin>>b;
    cout<<"Enter third length: ";
    cin>>c;

    Triangle t1(a, b, c);

    cout<<"Perimeter of Triangle is: ";
    cout<<fixed<<setprecision(2)<<t1.Perimeter()<<endl;
    cout<<"Area of the same Triangle is: ";
    cout<<fixed<<setprecision(2)<<t1.Area()<<endl;

    return 0;
}
