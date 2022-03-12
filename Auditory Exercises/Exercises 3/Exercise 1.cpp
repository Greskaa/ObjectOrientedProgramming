#include <iostream>

using namespace std;

class Point
{
//Accessible only by the class
private:
    int x, y;

//We define the constructor in public part which will work as a gateway for accessing the private part of the class
//Constructor should be the same name as the class
public:
    Point()
    {
        cout<<"This is the default constructor!"<<endl;
        x=0;
        y=0;
    }

  /*Point(int x, int y) // used like this, x and y are local variables (x and y from private part are not used)
    {
        x = x;
        y = y;
    }
  */

  Point(int _x, int _y) //like this we access the private part x and y
  {
      cout<<"This is the Parametrized Constructor (it has arguments)"<<endl;
      x = _x;
      y = _y;
  }

  ~Point() //At the end create a Destructor to delete the unused objects
  {
      cout<<"Object is destroyed\n";
  }

};

int main()
{
    //calling the default constructor
    Point p1; //p1 will have the values of x and y which in this case are 0 and 0

    //calling the parametrized constructor
    Point p2(10, 5); //we send the arguments to the
    
    return 0;
}
