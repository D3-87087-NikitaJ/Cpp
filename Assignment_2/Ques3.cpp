/*Q3. Write a class Address with data members 
(string building, string street, string city ,int pin)
Implement constructors, getters, setters, accept(), and display() methods.
Test the class functunalities by creating the object of class and 
calling all the functions*/


#include<iostream>
using namespace std;

class Address{
    string building;
    string street;
    string city;
    int pin;


public:
    Address() : building(""), street(""), city(""), pin(0)
    {

    }

    Address(string b, string s, string c, int p): building(b), street(s), city(c), pin(p){

    }

    string getBuilding(){
        return building;
    }

    void setBuilding(const string &b){
        building = b;
    }

    string getcity(){
        return city;
    }

    void setcity(const string &c){
        city = c;
    }

    string getStreet(){
        return street;
    }

    void setStreet(const string &s){
        street = s;
    }

    int getPin(){
        return pin;
    }

    void setPin(int p){
        pin = p;
    }


    void accept(){
        cout<<"Enter building: "<<endl;
        cin>>building;
        cout<<"Enter street: "<<endl;
        cin>>street;
        cout<<"Enter city: "<<endl;
        cin>>city;
        cout<<"enter pin: "<<endl;
        cin>>pin;

    }


    void display(){
        cout<<"Building : "<<building<<endl;
        cout<<"Street : "<<street<<endl;
        cout<<"city : "<<city<<endl;
        cout<<"pin : "<<pin<<endl;

    }



};

int main(){
    Address add;
    add.accept();
    cout<<"Address details: "<<endl;
    add.display();

    Address add2("Old TCG","Hinjewadi","Pune",440057);
    cout<<"Parameterized address details: "<<endl;
    add2.display();

    add2.setcity("Mumbai");
    cout<<"New city: "<<add2.getcity()<<endl;

    return 0;
}

