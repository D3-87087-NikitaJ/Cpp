/*Q2. Write a menu driven program for Student management.
Create a class student with data members name, gender, rollNumber(Auto generated) 
and array to keep marks of three subjects. 
Accept every thing from user and Print name, rollNumber, gender and percentage.
Provide global functions void sortRecords() and int searchRecords() 
for sorting and searching array.
In main(), create Student* arr[5] and provide facility for 
accept, print, search and sort.
Search function returns index of found Student, otherwise returns -1.
sortRecord sorts the students array based on roll no in descending order*/

#include<iostream>
using namespace std;

class Student{
    string name;
    string gender;
    int rollno;
    static int generate_rollno;
    float *marks;

public:
    Student(): name(""),gender(" "),rollno(++generate_rollno) {
        marks = new float[3];
     }

    Student(string name, string gender):rollno(++generate_rollno){
        this->name = name;
        this->gender = gender;
        marks = new float[3];

    }

    void accept(){
        cout<<"Enter name: "<<endl;
        cin>>name;
        cout<<"Enter gender: "<<endl;
        cin>>gender;
        cout<<"Enter marks: "<<endl;
        for(int i=0;i<3;i++){
            cin>>marks[i];
        }
    }

    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<rollno<<endl;
        cout<<"Gender: "<<gender<<endl;
        cout<<"Percentage: "<<endl;
        calculatePercentage();
    }

    void calculatePercentage(){
        cout<<(float(marks[0]+marks[1]+marks[2])/3)*100<<"%"<<endl;
    }

    int getRollnumber() const{
        return rollno;
    }

};

void sortRecord(Student *s){
    Student temp;
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(s[i].getRollnumber()<s[j].getRollnumber()){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

}

int searchRecord(Student *s){
    int rollnum;
    cout<<"Enter the roll number to be searched: "<<endl;
    cin>>rollnum;

    for(int i=0; i<5; i++){
        if(s[i].getRollnumber()==rollnum){
            s[i].display();
            return i;
        }
        else{
            cout<<"Student not found."<<endl;
        }
    }
}

int menu(){
    int choice;
    cout<<"0. EXIT"<<endl;
    cout<<"1. Accept Students"<<endl;
    cout<<"2. Display"<<endl;
    cout<<"3. Sort"<<endl;
    cout<<"4. Search"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;

    return choice;
}

int Student::generate_rollno = 0;

int main(){

    Student *s1 = new Student[5];

    int ch;
    while((ch=menu())!=0){
        switch(ch){
            case 1: cout<<"Enter student data: "<<endl;
                for(int i=0; i<5; i++){
                    s1[i].accept();
                    
                }
                break;
            case 2: cout<<"Student data: "<<endl;
                for(int i=0; i<5; i++){
                    s1[i].display();
                    
                }
                break;
            case 3: cout<<"Sorting : "<<endl;
                sortRecord(s1);
                for(int i=0; i<5; i++){
                    s1[i].display();
                    
                }
                break;
            case 4: cout<<"Searching :"<<endl;
                searchRecord(s1);
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
            

    }

    }
    delete[] s1;
    


    return 0;
}