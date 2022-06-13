#include<iostream>
#include<cstring>

using namespace std;

enum Color{RED, GREEN, BLUE};
//          0     1     2

class Shape
{
private:
    Color color;
    char id[5]; //+1 for the null terminator
    double area;
public:
    //Default Constructor
    Shape(){}
    //Constructor with parameters
    Shape(char *id, Color color, double area)
    {
        strcpy(this->id, id);
        this->color = color;
        this->area = area;
    }
    //Copy Constructor
    Shape(const Shape &sh)
    {
        strcpy(id, sh.id);
        color = sh.color;
        area = sh.area;
    }
    //Destructor
    ~Shape(){}

    void printColor()
    {
        if (color == 0)
            cout<<"RED";
        else if (color == 1)
            cout<<"GREEN";
        else
            cout<<"BLUE";
    }

    Color getColor()
    {
        return color;
    }

    double getArea()
    {
        return area;
    }

    void draw()
    {
        cout<<id<<" ";
        printColor();
        cout<<" "<<area<<endl;
    }

    void reduceArea()
    {
        area = area/2;
    }
};

class Canvas
{
private:
    Shape shapes[100];
    int shapesNumber; //because it says for n to be initially 0 we should do that to the default constructor
public:
    //Default Constructor
    Canvas()
    {
        shapesNumber = 0;
    }
    //Constructor with parameters not needed because in the main function we do not pass any arguments
    //Copy Constructor
    Canvas(const Canvas &c)
    {
        shapesNumber = c.shapesNumber;
        for (int i=0; i<c.shapesNumber; i++)
        {
            shapes[i] = c.shapes[i];
        }
    }
    //Destructor
    ~Canvas(){}

    void addShape(Shape &s) //we put reference to avoid calls from the Copy Constructor
    {
        shapes[shapesNumber++] = s; //depending on how many shapes we have, it adds exactly that much to the array
    }

    void drawAll()
    {
        for (int i=0; i<shapesNumber; i++)
        {
            shapes[i].draw();
        }
    }

    void drawOnly(Color color)
    {
        for (int i=0; i<shapesNumber; i++)
        {
            if (color == shapes[i].getColor())
                shapes[i].draw();
        }
    }

    double totalArea()
    {
        double total=0;
        for (int i=0; i<shapesNumber; i++)
        {
            total = total + shapes[i].getArea();
        }
        return total;
    }

    Canvas getHalfCanvas()
    {
        Canvas copy(*this); //creating a copy from the current object
        for (int i=0; i<copy.shapesNumber; i++) //copy.shapesNumber because we're iterating the copy canvas
        {
            copy.shapes[i].reduceArea(); //copy.shapes[i] because we're iterating the copy shapes
        }
        return copy;
    }
};
int main ()
{
	int n;
	cin>>n;
	cout<<"ADITION OF SHAPES IN THE CANVAS"<<endl;
	Canvas canvas;

	for (int i=0;i<n;i++)
	{
		char id [5];
		int color;
		double area;

		cin>>id>>color>>area;
		Shape s (id, (Color) color, area);
		canvas.addShape(s);
	}

	cout<<"TESTING DRAW ALL"<<endl;

	canvas.drawAll();

	cout<<"TESTING DRAW RED SHAPES"<<endl;

	canvas.drawOnly(RED);

	cout<<"TESTING TOTAL AREA"<<endl;

	cout<<canvas.totalArea()<<endl;

	cout<<"TESTING HALF CANVAS"<<endl;
	Canvas reducedCanvas = canvas.getHalfCanvas();
	cout<<canvas.totalArea()<<" "<<reducedCanvas.totalArea()<<endl;

	if (reducedCanvas.totalArea() == canvas.totalArea()) {
		cout<<"DO NOT CHANGE THE AREA OF THE OBJECT IN THE CURRENT CANVAS. JUST IN THE NEW CANVAS"<<endl;
	}

	return 0;
}
