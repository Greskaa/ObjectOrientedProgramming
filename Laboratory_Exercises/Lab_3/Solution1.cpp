#include <iostream>
#include <cstring>

using namespace std;

class Potpisuvac
{
private:
    char name[20];
    char surname[20];
    char sscNumber[14];
public:
    //Default Constructor
    Potpisuvac(){}
    //Constructor with arguments
    Potpisuvac(char *name, char *surname, char *sscNumber)
    {
        strcpy(this->name, name);
        strcpy(this->surname, surname);
        strcpy(this->sscNumber, sscNumber);
    }
    //Copy Constructor
    Potpisuvac(const Potpisuvac &p)
    {
        strcpy(name, p.name);
        strcpy(surname, p.surname);
        strcpy(sscNumber, p.sscNumber);
    }

    char *getSSC()
    {
        return sscNumber;
    }

    //Destructor
    ~Potpisuvac(){}
};

class Dogovor
{
private:
    int agreement_id;
    char agreement_category[50];
    Potpisuvac agreement_signers[3];
public:
    //Default Constructor
    Dogovor(){}
    //Constructor with parameters
    Dogovor(int agreement_id, char *agreement_category, Potpisuvac *agreement_signers)
    {
        this->agreement_id = agreement_id;
        strcpy(this->agreement_category, agreement_category);
        for (int i=0; i<3; i++)
        {
            this->agreement_signers[i] = agreement_signers[i];
        }
    }
    //Copy Constructor
    Dogovor(const Dogovor &d)
    {
        agreement_id = d.agreement_id;
        strcpy(agreement_category, d.agreement_category);
        for (int i=0; i<3; i++)
        {
            agreement_signers[i] = d.agreement_signers[i];
        }
    }
    //Destructor
    ~Dogovor(){}

    //Method for checking Social Security Number
    bool proverka()
    {
        for (int i=0; i<3; i++)
        {
            if (strcmp(agreement_signers[0].getSSC(), agreement_signers[1].getSSC()) == 0 ||
                strcmp(agreement_signers[1].getSSC(), agreement_signers[2].getSSC()) == 0 ||
                strcmp(agreement_signers[2].getSSC(), agreement_signers[0].getSSC()) == 0)
                return true;
        }
            return false;
    }
};

int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
    	cin >> embg >> ime >> prezime;
    	Potpisuvac p1(ime, prezime, embg);

    	cin >> embg >> ime >> prezime;
    	Potpisuvac p2(ime, prezime, embg);

    	cin >> embg >> ime >> prezime;
    	Potpisuvac p3(ime, prezime, embg);

    	cin >> broj >> kategorija;
    	Potpisuvac p[3];
    	p[0] = p1; p[1] = p2; p[2] = p3;

    	Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl;

    	if(d.proverka() == true)
    	    cout << "Postojat potpishuvaci so ist EMBG" << endl;
    	else
    	    cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }

    return 0;
}
