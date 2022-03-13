#include <iostream>

using namespace std;

class Circle
{
private:
    float radius;
    const float pi=3.14;

public:
    //Default Constructor + Parametrized (2 in 1 -> like Nescafe:D)
    Circle(float _radius=2)
    {
        radius = _radius;
    }

    float area()
    {
        return pi * radius * radius;
    }

    float perimeter()
    {
        return pi*2*radius;
    }

    //Method that compares Perimeter and Area
    bool equal()
    {
        if (perimeter() == area())
            return true;
        else
            return false;
    }

    ~Circle()
    {

    }
};

int main()
{
    float r;
	cin >> r;
	//instanciate object from class Circle
    Circle c(r);
	cout << c.perimeter() << endl;
	cout << c.area() << endl;
	cout << c.equal() <<endl;

    return 0;
}
