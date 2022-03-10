#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Student
{
    //Define the structure Student with the required properties
    char first_name[50];
    char last_name[50];
    char ID[10];
    int total_grades;
    int grades[40];
};

typedef struct Student student;

//Define 2 methods - one for reading and one for writing the Student
void Read_Student(student *s)
{
    //When we read strings in scanf we don't put & sign while dealing with pointers,
    //because doing so will point to the firs characters of the strings
    printf("Enter first name, last name and ID number of the student: \n");
    scanf("%s %s %s", s->first_name, s->last_name, s->ID);
    //Read the total number of grades the student has acomplished
    printf("Enter total number of grades: ");
    scanf("%d", &s->total_grades);
    //With a for loop we are going to read the grades for each subject
    for (int i=0; i<s->total_grades; i++)
    {
        printf("Enter grade: ");
        scanf("%d", &s->grades[i]);
    }
}

float Average_Grade(student s)
{
    float sum=0;
    for (int i=0; i<s.total_grades; i++)
    {
        if (s.grades[i] > 5)
            sum += s.grades[i];
    }
    return sum/s.total_grades;
}

//The first Letter of the name should be capital and the others lowercase
void Normalize_Name(char *name)
{
    name[0] = toupper(name[0]);
    for (int i=1; i<strlen(name); i++)
    {
        name[i] = tolower(name[i]);
    }
}

void Print_Student(student s)
{
    //Normalize both the name and the surname of the student (Call the function Normalize before printing out the result)
    Normalize_Name(s.first_name);
    Normalize_Name(s.last_name);
    //Print name, surname, ID and Avg grade.
    printf("Name: %s\nSurname: %s\nID: %s\nAverage Grade: %.2f", s.first_name, s.last_name, s.ID, Average_Grade(s));
}

int main()
{
    student student_1;
    Read_Student(&student_1);
    Print_Student(student_1);

    return 0;
}
