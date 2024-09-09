/* 
Q1. Create a class Date with data memebrs day,month and year. 
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of 
type Date. 
Implement above classes. Test all functionalities in main()*/

#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptDate()
    {
        cout << "Enter day month and year - ";
        cin >> day >> month >> year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};
class person
{
    string name;
    string address;
    Date birthdate;

public:
    person()
    {
        this->name = "";
        this->address = "";
    }

    person(string name, string number)
    {
        this->name = name;
        this->address = address;
    }

    void acceptperson()
    {
        cout << "Enter the name of the person - ";
        cin >> name;
        cout << "Enter the address - ";
        cin >> address;
        //cout << "Enter the date of joining - " << endl;
        birthdate.acceptDate();
    }

    void displaypersonDetails()
    {
        cout << "person Name - " << name << endl;
        cout << "person address - " << address << endl;
        cout << "Date of Joining -> ";
        birthdate.displayDate();
        
    }
};


int main()
{
    person e1;
    e1.acceptperson();
    e1.displaypersonDetails();
    
    // person e2;
    // e2.acceptperson();
    //e2.displaypersonDetails();

    
    
    return 0;
}