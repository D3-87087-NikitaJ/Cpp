/*Q2. Write a menu driven program for Date in a CPP language using
 structure and also using class.
Date is having data members day, month, year. Implement the following 
functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear();*/

#include<iostream>
using namespace std; 



class Date{
    int day;
    int month;
    int year;

public:
    void initDate(){
        day = 1;
        month = 1;
        year = 1;
        
    }


    void display(){
        cout<< "Date : " <<day <<"/"<< month<<"/"<<year<<endl;

    }

    void accept(){
        cout<<"Enter the date, month and year ";
        cin>> day >>month >>year;
    }

    bool isleap_yr(){
        bool isleap_yr = false;
        if((year%4==0 && (year%100!=0)) || (year%400==0)){
            bool isleap_yr = true;
        }
        if(isleap_yr==0){
            return false;
        }
        else{
            return true;
        }
        
        

        }
};




int menu(){
    int choice;
    cout<<"0. Exit"<<endl;
    cout<<"1. Accept Date"<<endl;
    cout<<"2. Display Date"<<endl;
    cout<<"3. Check Leap year"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    Date d1;
    while((choice = menu()) != 0){
        switch (choice)
        {
        case 1:
            d1.accept();
            break;

        case 2:
            d1.display();
            break;

        case 3:
            if(d1.isleap_yr()){
                cout<<"Year is a leap year"<<endl;
            }
            else{
                cout<<"year is not a leap year."<<endl;
            }
            
            break;
        
        default:
            cout<< "Wrong choice"<<endl;
            break;
        }
    }

    return 0;
}


