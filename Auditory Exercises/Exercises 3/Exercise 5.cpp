#include <iostream>
#include <cstring>
#include <iomanip>
#include <string.h>

using namespace std;

class Student
{
private:
    char name[20];
    char surname[20];
    char index[10];
    int age;
    int total_exams;
    int exam_grades[40];
public:
    //Default Constructor
    Student(){}

    //Constructor with parameters
    Student(char *_name, char *_surname, char *_index, int _age, int _total_exams, int *_exam_grades)
    {
        strcpy(name, _name);
        strcpy(surname, _surname);
        strcpy(index, _index);
        age = _age;
        total_exams = _total_exams;
        for (int i=0; i<40; i++)
        {
            exam_grades[i] = _exam_grades[i];
        }
    }

    //Method for printing the Student's information
    void printStudent()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Surname: "<<surname<<endl;
        cout<<"Index: "<<index<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Total Exams taken: "<<total_exams<<"/40"<<endl;
        cout<<"Average grade: "<<fixed<<setprecision(2)<<AverageGrade()<<endl;
    }

    //Method for inputing grades for exams taken
    void readGrades()
    {
        for (int i=0; i<total_exams; i++)
        {
            cout<<"Enter grade for exam "<<i+1<<endl;
            cin>>exam_grades[i];
            AverageGrade();
        }
    }

    float AverageGrade()
    {
        float sum=0;
        for (int i=0; i<total_exams; i++)
        {
            if (exam_grades[i] >= 6 && exam_grades[i] <= 10)
                sum += exam_grades[i];
        }
        return sum/total_exams;
    }
};

char NormalizeName(char *name)
{
    name[0] = toupper(name[0]);
    for (int i=1; i<strlen(name); i++)
    {
        name[i] = tolower(name[i]);
    }
    return *name;
}

int main()
{

    int n;
    cout<<"Enter for how many students you want to gather information: ";
    cin>>n;

    Student students[n];

    for (int i=0; i<n; i++)
    {
        char name[20];
        char surname[20];
        char index[10];
        int age;
        int total;
        int exams[40];

        cin>>name;
        cin>>surname;
        cin>>index;
        cin>>age;
        cin>>total;

        NormalizeName(name);
        NormalizeName(surname);

        students[i] = Student(name, surname, index, age, total, exams);

        students[i].readGrades();

        students[i].printStudent();
    }


    return 0;
}
