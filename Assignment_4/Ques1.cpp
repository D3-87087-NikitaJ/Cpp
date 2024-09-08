/*Q1. Create a class Date with data memebrs day,month and year.
Create a class Person with data members name,address and birthdate. 
The birthdate shoud be of type Date.
Implement above classes. Test all functionalities in main().*/

#include<iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date() : day(0), month(0), year(0000) {

    }

    Date(int day, int month, int year): day(day), month(month), year(year) { }

    void acceptDate(){
        cout<<"Enter day: "<<endl;
        cin>>day;
        cout<<"Enter month: "<<endl;
        cin>>month;
        cout<<"Enter year: "<<endl;
        cin>>year;
        
    }

    void displayDate(){
        cout<<"Date: "<<day<<"/"<<month<<"/"<<year<<endl;
    }
};

class Person{
    string name;
    string address;

    Date dob;

public:
    Person() : name(""), address(""), dob() { }

    Person(string name, string address, Date dob) : name(name), address(address), dob(dob) { }

    void acceptPersonDetails(){
        cout<<"Enter name: "<<endl;
        cin>>name;
        cout<<"Enter address: "<<endl;
        cin>>address;
        cout<<"Enter date of joining: "<<endl;
        dob.acceptDate();
    }

    void displayPersonDetails(){
        cout<<"Name of person: "<<name<<endl;;
        cout<<"Address: "<<address<<endl;
        cout<<"Birthdate: "<<endl;
        dob.displayDate(); 
    }
};

int main(){

    Person p1;
    p1.acceptPersonDetails();
    p1.displayPersonDetails();

    return 0;
}               