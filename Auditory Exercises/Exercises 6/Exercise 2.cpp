#include <iostream>
#include <cstring>

using namespace std;

class Student
{
private:
    char *name;
    int academicYear;
    int *grades;
    int numGrades;
public:
    //Default Constructor + Constructor with parameters
    Student(char *name="", int academicYear=0)
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
        this->academicYear = student.academicYear;
        this->numGrades = student.numGrades;
        this->name = new char[strlen(student.name)+1];
        strcpy(this->name, name);
        this->grades = new int[student.numGrades];
        for (int i=0; i<student.numGrades; i++)
        {
            this->grades[i] = student.grades[i];
        }
    }
    //Assignment Operator Overloading
    Student & operator = (const Student &student)
    {
        if (this != &student)
        {
            delete []name;
            delete []grades;

            this->academicYear = student.academicYear;
            this->numGrades = student.numGrades;
            this->name = new char[strlen(student.name)+1];
            strcpy(this->name, student.name);
            this->grades = new int[student.numGrades];
            for (int i=0; i<student.numGrades; i++)
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

    //Method for calculating average grade
    double AverageGrade() const //add const because the output of the Student reference is a constant (otherwise it pops up error)
    {
        double sum=0;
        if (numGrades == 0)
            return 5.0;
        else
        {
            for (int i=0; i<numGrades; i++)
            {
                sum += grades[i];
            }
        }
        return (double)sum/numGrades;
    }

    //Reading Operator
    friend istream& operator >> (istream &in, Student &student)
    {
        cout<<"Enter name: ";
        in>>student.name;
        cout<<"Enter academic year: ";
        in>>student.academicYear;

        return in;
    }

    //Printing Operator
    friend ostream& operator << (ostream &out, const Student &student)
    {
        //Name, academic year, avg grade
        cout<<"Student's name: "<<student.name<<endl;
        cout<<"Student's academic year: "<<student.academicYear<<endl;
        cout<<"Student's Average grade: ";
        student.AverageGrade();
        cout<<endl;

        return out;
    }

    //Prefix Operator (no arguments)
    Student & operator++()
    {
        ++academicYear;
        return *this;
    }

    //Postfix Operator (dummy argument)
/*  Student operator++(int)
    {
        Student copy(*this);
        ++academicYear;
        return copy;
    }
*/

    //Greater than Operator for comparing students based on their average grade
    bool operator > (Student &student)
    {
        return this->AverageGrade() > student.AverageGrade(); //1 if true
    }
};

class Faculty
{
private:
    Student *students;
    int numStudents;
public:
    //Default Constructor
    Faculty()
    {
        this->numStudents = 0;
        this->students = new Student[0];
        for (int i=0; i<numStudents; i++)
        {
            this->students[i] = students[i];
        }
    }
    //Copy Constructor
    Faculty(const Faculty &faculty)
    {
        this->numStudents = faculty.numStudents;
        this->students = new Student[faculty.numStudents];
        for (int i=0; i<faculty.numStudents; i++)
        {
            this->students[i] = faculty.students[i];
        }
    }
    //Assignment Operator Overloading
    Faculty& operator = (const Faculty &faculty)
    {
        if (this != &faculty)
        {
            delete []students;

            this->numStudents = faculty.numStudents;
            this->students = new Student[faculty.numStudents];
            for (int i=0; i<faculty.numStudents; i++)
            {
                this->students[i] = faculty.students[i];
            }
        }
        return *this;
    }
    //Destructor
    ~Faculty()
    {
        delete []students;
    }

    //+= Operator for adding a student
    Faculty & operator += (const Student &newStudent)
    {
        Student *temp = new Student[numStudents + 1];
        for (int i=0; i<numStudents; i++)
        {
            temp[i] = students[i];
        }
        temp[numStudents++] = newStudent;
        delete []students;
        students = temp;
        return *this;
    }

    //++ Operator (prefix way)
    Faculty & operator ++ ()
    {
        for (int i=0; i<numStudents; i++)
        {
            ++students[i];
        }
    }

    //Operator for printing the students
    friend ostream& operator << (ostream &out, const Faculty &faculty)
    {
        for (int i=0; i<faculty.numStudents; i++)
        {
            cout<<faculty.students[i];
        }
        return out;
    }

    //Method that will print only the student with average grade higher than 9.00
    void Reward()
    {
        for (int i=0; i<numStudents; i++)
        {
            if (students[i].AverageGrade() >= 9.00)
                cout<<students[i];
        }
    }

    //Method for printing the highest average in the group of students
    void highestAverage()
    {
        double maxAvg = students[0].AverageGrade();
        for (int i=1; i<numStudents; i++)
        {
            double saveAvgStudent = students[i].AverageGrade(); //to avoid calling the AverageGrade() function too many times
            if (saveAvgStudent > maxAvg)
                maxAvg = saveAvgStudent;
        }
    }

    //Operator [] for mutable access for the student in position index
    Student & operator[] (int index) //argument is the index to the student
    {
        return students[index];
    }
};


int main()
{
    Faculty f1;
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    for (int i=0; i<n; i++)
    {
        Student s1;
        cin>>s1;
        cout<<s1;
        cout<<++s1; //increments the academic year immediately
        f1 += s1;
    }

    cout<<f1;

    //cout<<s1++; //increments the academic year the next line
  
    return 0;
}
