/*Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected 
to pay a fifty-cent toll. 
Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by and of 
the total amount of money 
collected. Model this tollbooth with a class called tollbooth.
The two data items are a type unsigned int to hold the total number of cars, 
and a type double to 
hold the total amount of money collected.
A constructor initializes all data members to 0. A member function 
called payingCar() increments 
the car total and adds 0.50 to the cash total. An other function, called nopayCar()
increments the car total but adds nothing to the cash total. Finally, a member function 
called 
printOnConsole() displays the two totals and number of paying as well as 
non paying cars total.*/

#include<iostream>
using namespace std;

class tollbooth{
    unsigned int totalCars;
    double totalMoney;
    unsigned int payingCars;
    unsigned int nopayingCars;

public:
    tollbooth() : totalCars(0), totalMoney(0.0), payingCars(0), nopayingCars(0)
    {

    }

    void payingCar(){
        totalCars++;
        payingCars++;
        totalMoney+=0.50;
    }

    void nopayingCar(){
        totalCars++;
        nopayingCars++;
    }

    void printOnConsole() const{
        cout<<"Total cars: "<<totalCars<<endl;
        cout<<"Paying cars: "<<payingCars<<endl;
        cout<<"No paying cars: "<<nopayingCars<<endl;
        cout<<"Total Money: "<<totalMoney<<endl;


    }

};

int menu(){
    int choice;
    cout<<"0. EXIT"<<endl;
    cout<<"1. Paying Cars "<<endl;
    cout<<"2. No paying Cars "<<endl;
    cout<<"3. Display tollbooth "<<endl;
    cin>>choice;

    return choice;
}

int main(){
    tollbooth Cars;
    int ch;

    while((ch = menu()) != 0){
        switch(ch){
            case 1: Cars.payingCar();
            break;

            case 2: Cars.nopayingCar();
            break;

            case 3: Cars.printOnConsole();
            break;

            default: 
                cout<<"default choice";
                break;
        }
    }

    return 0;
}