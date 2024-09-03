/*Q4. Create a namespace NStudent. 
Create the Student class(created as per Q3) inside namespace. 
Create the object of student and perform accept 
and display student*/

#include<iostream>
using namespace std;

namespace NStudent
{
    class Student{
        int rollno;
        string name;
        int marks;

public:
    void initStud(){
        rollno = 0;
        name = "anonymous";
        marks = 10;
    }

    void printStud(){
        cout<<"Roll no. : "<<rollno<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Marks : "<<marks<<endl;
    }

    void acceptStud(){
        cout<<"Enter the roll no. , name and marks of student :"<<endl;
        cin>>rollno>>name>>marks;
    }
    };

}

int main()
{   
    NStudent::Student s1;
    s1.acceptStud();
    s1.printStud();

    return 0;
}