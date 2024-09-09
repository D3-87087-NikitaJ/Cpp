/*Q1. Create a class Date with data memebrs day,month and year. 
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of 
type Date. 
Cretae a class Employee with data members id, sal, dept and joining date. The joining date should 
be of type date. 
Employee class should be inherited from Person. 
Implement following classes. Test all functionalities in main(). 
(Note - Perform the Association and Inheritance in the above case.) */

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

class Person
{
    string name;
    string address;
    Date birthdate;

public:
    Person()
    {
        this->name = "";
        this->address = "";
    }

    Person(string name, string number)
    {
        this->name = name;
        this->address = address;
    }

    virtual void accept()
    {
        cout << "Enter the name of the person - ";
        cin >> name;
        cout << "Enter the address - ";
        cin >> address;
        //cout << "Enter the date of joining - " << endl;
        birthdate.acceptDate();
    }

    virtual void display()
    {
        cout << "person Name - " << name << endl;
        cout << "person address - " << address << endl;
        cout << "Date of Joining -> ";
        birthdate.displayDate();
        
    }
};

class Employee : public Person
{
    int id;
    double salary;
    string department;
    Date joiningdate;

public:
    Employee()
    {
    }
    Employee(int empid, string name, double salary) 
    {
        this->id = empid;
        this->salary = salary;
    }
    void accept()
    {
        cout << "Enter emp id - ";
        cin >> id;

        Person::accept();

        cout << "Enter salary - ";
        cin >> salary;
    }

    void display()
    {
        cout << "Empid - " << id << endl;
        Person::display();
        cout << "Salary - " << salary << endl;
    }

    void calculateTax()
    {
        cout << "Total Tax = " << (0.1 * salary) << endl;
    }
};

int main()
{
    Person *ptr = new Employee(); // upcasting
    ptr->accept();
    ptr->display();

     Employee *dptr = (Employee *)ptr;
    dptr->calculateTax();
    

    // Employee e;
    // e.accept();
    // e.display();
   

    // person e2;
    // e2.acceptperson();
    //e2.displaypersonDetails();

    
    
    return 0;
}


