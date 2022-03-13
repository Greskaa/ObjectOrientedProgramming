#include <iostream>
#include <string.h>

using namespace std;

class EmailMessage
{
private:
    char sender[50];
    char receiver[50];
    char subject[50];
    char body[500];

public:
    EmailMessage(char *_sender="info@finki.ukim.mk",
                 char *_receiver="gresa.kadriu@students.finki.ukim.mk",
                 char *_subject="Primatijada",
                 char *_body="Dear student,\nPlease open and read carefully the attached document about the trip in Budva\nGive us feedback if you are coming or not\nBest regards,\nFINKI Faculty\n")
    {
        strcpy(sender, _sender);
        strcpy(receiver, _receiver);
        strcpy(subject, _subject);
        strcpy(body, _body);
    }

    void Print_Mail()
    {
        cout<<"Sender: "<<sender<<endl;
        cout<<"Receiver: "<<receiver<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"Subject: "<<subject<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<body<<endl;
        cout<<"ENDS"<<endl<<endl;
    }
};

bool valid_email(char *mail)
{
    char *pointer = strchr(mail, '@'); //find the @ character in the email and validates accordingly
    if (pointer != nullptr)
        return strchr(pointer, '.') != nullptr;
    else
        return false;
}

int main()
{
    char sender[50], receiver[50], subject[50], body[500];
    cout<<"Enter sender email address: ";
    cin.getline(sender, 50);
    cout<<"Enter receiver email address: ";
    cin.getline(receiver, 50);

    if (valid_email(sender) && valid_email(receiver))
    {
        cout<<"Enter subject of email: ";
        cin.getline(subject, 50);
        cout<<"Enter message: ";
        cin.getline(body, 500);
        EmailMessage email(sender, receiver, subject, body);
        email.Print_Mail();
    }
    else
        cout<<"The email provided is invalid! Try again!";

    return 0;
}
