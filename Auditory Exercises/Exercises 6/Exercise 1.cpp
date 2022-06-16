#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    char *name;
    int *grades; //initially no grades
    int numGrades;
    int academicYear;
public:
    //Default Constructor + Constructor with parameters
    Student(char *name="", int academicYear=0) //because there's no grades initially we just have name and year as arguments
    {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->academicYear = academicYear;
        this->numGrades = 0;
        this->grades = new int[0];
    }
    //Copy Constructor
    Student(const Student &student)
    {
        this->name = new char[strlen(student.name)+1];
        strcpy(this->name, student.name);
        this->academicYear = student.academicYear;
        this->numGrades = student.numGrades;
        this->grades = new int[student.numGrades];
        for(int i=0; i<student.numGrades; i++)
        {
            this->grades[i] = student.grades[i];
        }
    }
    //Assignment Operator Overloading
    Student& operator = (const Student &student)
    {
        if (this != &student)
        {
            delete []name;
            delete []grades;

            this->name = new char[strlen(student.name)+1];
            strcpy(this->name, student.name);
            this->academicYear = student.academicYear;
            this->numGrades = student.numGrades;
            this->grades = new int[student.numGrades];
            for(int i=0; i<student.numGrades; i++)
            {
                this->grades[i] = student.grades[i];
            }
        }
        return *this;
    }
    //Destructor
    ~Student()
    {
        delete []name;
        delete []grades;
    }

    double getAverageGrade() const //we must make the method a const because the ostream is const (otherwise it's an error)
    {
        if (numGrades == 0) //start of academic year student has no passed exams so the avg is 5.00 (mathematically we cannot divide with 0)
        {
            return 5.0;
        }

        double sum=0;
        for (int i=0; i<numGrades; i++)
        {
            sum +=grades[i];
        }
        return (double)sum/numGrades;
    }


    //Reading Operator
    friend istream& operator >> (istream &in, Student &student)
    {
        cout<<"Enter name of student: ";
        in>>student.name;
        cout<<"Enter in which academic year the student is following the courses: ";
        in>>student.academicYear;

        return in;
    }
    //Printing Operator
    friend ostream& operator << (ostream &out, const Student &student)
    {
        //Name, year, avg grade of student's exams
        cout<<"Name: "<<student.name<<endl;
        cout<<"Academic Year: "<<student.academicYear<<endl;
        cout<<"Average grade: ";
        student.getAverageGrade();
        cout<<endl;

        return out;
    }
    //Prefix Operator
    Student& operator++() //doesn't accept any argument
    {
        ++academicYear;
        return *this;
    }
};

int main()
{
    Student s1;
    cin>>s1;
    cout<<s1;
    cout<<++s1;

    return 0;
}
