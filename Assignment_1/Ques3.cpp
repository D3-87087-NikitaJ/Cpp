/*Q3. Write a menu driven program for Student in CPP language. 
Create a class student with data members roll no, name and marks.
Implement the following functions
void initStudent();
void printStudentOnConsole();
void acceptStudentFromConsole();*/

#include<iostream>
using namespace std;

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

int menu(){
    int choice;
    cout<<"0. EXIT"<<endl;
    cout<<"1. Accept Student"<<endl;
    cout<<"2. Display Student"<<endl;
    cin>>choice;
    return choice;

}

int main()
{   
    int ch;
    Student s1;
    
    while((ch = menu()) !=0){
        switch (ch)
        {
        case 1:
            s1.acceptStud();
            break;
        
        case 2:
            s1.printStud();
        default:
            cout<<"Wrong choice"<<endl;
            break;
        }
    }
    return 0;
}