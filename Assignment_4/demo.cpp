/*
Q2. Write a menu driven program for Student management.
Create a class student with data members name, gender, rollNumber(Auto generated) and array to
keep marks of three subjects.
Accept every thing from user and Prdouble name, rollNumber, gender and percentage.
Provide global functions void sortRecords() and double searchRecords() for sorting and searching array.
In main(), create Student* arr[5] and provide facility for accept, prdouble, search and sort.
Search function returns index of found Student, otherwise returns 1.
sortRecord sorts the students array based on roll no in descending order.
*/

#include <iostream>

using namespace std;

class Student
{
    string name;
    string gender;
    static int generate_rollNo;     // Static because its most recent value doesnot gets destroyed
    int rollNumber;
    int *marks;

public:
    Student() : rollNumber(generate_rollNo++)   // Parameterless ctor
    {
        name = " ";
        gender = " ";
        marks = new int[3];
    }
    Student(string name, string gender) : rollNumber(generate_rollNo++) // ctor initialization list
    {
        this->name = name;
        this->gender = gender;
        marks = new int[3];     // Array for subjects
    }

    void acceptStudent()
    {
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the gender: ";
        cin >> gender;
        cout << "Enter the marks-> " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter the marks for subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    int calculatePercentage()
    {
        int sum;
        for (int i = 0; i < 3; i++)
        {
            sum += marks[i];
        }
        return (sum / 3);
    }

    void displayStudent()
    {

        cout << "Roll No:  " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Percentage: " << calculatePercentage() << endl;
    }

    int getRollNumber() const       // making inspector const because we are not changing any value.<- good practice
    {
        return rollNumber;
    }
};

int Student ::generate_rollNo = 1;  // Static data member initiation with default values

void sortRecord(Student *s)
{
    int min = 0;
    Student temp; // Creating temp object for swap

    for(int i = 0 ; i<5 ; i++)
    {
        for(int j = i+1 ; j<5 ; j++)
        {
            if(s[i].getRollNumber() < s[j].getRollNumber())
            {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int searchRecord(Student *s)
{

    int rollNo;

    cout<<"Enter the roll no: ";
    cin>>rollNo;

    for(int i = 0 ; i<5; i++)
    {
       if( s[i].getRollNumber() == rollNo)
       {
        s[i].displayStudent();
        return i;
       }
       else
       {
            cout << " Student not found" << endl;
       }
    }
    return -1;

}

int menu()
{
    int choice;
    cout<<"0. EXIT"<<endl;
    cout<<"1. Accept Student"<<endl;
    cout<<"2. Display Student"<<endl;
    cout<<"3. Sort Student"<<endl;
    cout<<"4. Search Student"<<endl;
    cout<<"Enter the choice: ";
    cin>>choice;
    return choice;
}

int main()
{

    Student *s1 = new Student[5];

    int choice;

    while((choice=menu())!=0)
    {
        switch(choice)
        {
            case 1:
            cout<<"Enter Student Data"<<endl;
            for(int i = 0 ; i<5 ; i++)
            {
                s1[i].acceptStudent();
            }
            break;
            case 2:
            cout<<"Student Data"<<endl;
            for(int i = 0 ; i<5 ; i++)
            {
                s1[i].displayStudent();
            }
            break;

            case 3:
            cout<<"Sorted Student Data"<<endl;
            sortRecord(s1);
            for(int i = 0 ; i<5 ; i++)
            {
                s1[i].displayStudent();
            }
            break;

            case 4:
            cout<<searchRecord(s1);
            break;
            default:
            cout<<"Invalid choice"<<endl;
            break;
            
        }
    }

    delete [] s1;

    return 0;
}