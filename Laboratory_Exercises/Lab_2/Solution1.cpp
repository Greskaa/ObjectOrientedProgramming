#include <iostream>

using namespace std;

class Angle
{
private:
    int degrees;
    int minutes;
    int seconds;
public:
    //Predefined Values Constructor
    Angle(int _degrees=0, int _minutes=0, int _seconds=0)
    {
        degrees = _degrees;
        minutes = _minutes;
        seconds = _seconds;
    }
    //Destructor
    ~Angle(){}

    //Getters
    int getDegrees()
    {
        return degrees;
    }
    int getMinutes()
    {
        return minutes;
    }
    int getSeconds()
    {
        return seconds;
    }

    //Setters
    void setDegrees(int _degrees)
    {
        degrees = _degrees;
    }
    void setMinutes(int _minutes)
    {
        minutes = _minutes;
    }
    void setSeconds(int _seconds)
    {
        seconds = _seconds;
    }

    //Convert to Seconds
    int toSeconds()
    {
        return degrees*3600 + minutes*60 + seconds;
    }

    //Check validity
    bool check(int d, int m, int s)
    {
        if (d>=0 && d<360 && m>=0 && m<60 && s>=0 && s<60)
            return true;
        else if (d==360 && m==0 && s==0)
            return true;
        else
            return false;
    }
};

bool checkAngle (Angle a1, int deg, int min, int sec)
{
    return a1.getDegrees()==deg && a1.getMinutes()==min && a1.getSeconds()==sec;
}

int main()
{
    //Instantiate object of class Angle, named a1
    Angle a1;
    int deg, min, sec;

    cin >> deg >> min >> sec;

    if (a1.check(deg, min, sec)) {

    	a1.setDegrees(deg);
        a1.setMinutes(min);
        a1.setSeconds(sec);
        cout << a1.toSeconds();

        if (!checkAngle(a1,deg,min,sec)) {
            cout<<"Don't change the internal state of the private variables in the class!!!!";
        }

    } else {
    	cout << "Invalid values" << endl;
    }

    return 0;
}
