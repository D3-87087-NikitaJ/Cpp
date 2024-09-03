/*Q1. Write a menu driven program to calculate volume of the box(length * width * height).
Provide parameterless, parameterized(with 3 parameters) and 
single paramaterized constructor.
Create the local objects in respective case and call the function to caluclate area.
Menu options -> 
1. Calculate Volume with default values
2. Calculate Volume with length,breadth and height with same value
3. Calculate Volume with different length,breadth and height values.*/

#include<iostream>
using namespace std;

class Volume{
    int length;
    int width;
    int height;

public:
    Volume(){
        cout<<"Inside parameterless ctor"<<endl;
        length = 1;
        width = 1;
        height = 1;
    }

    Volume(int length,int width, int height){
        cout<<"Inside parameterised ctor"<<endl;
        this->length=length;
        this->width=width;
        this->height=height;

    }

    Volume(int value){
        length=value;
        width=value;
        height=value;
    }

    int calculateVolume() {
        return length*width*height;

        

    }

};

int menu(){
    int choice;
    cout<<"0. EXIT"<<endl;
    cout<<"1. Calculate Volume with default values "<<endl;
    cout<<"2. Calculate Volume with length,breadth and height with same value"<<endl;
    cout<<"3. Calculate Volume with different length,breadth and height values."<<endl;
    cin>>choice;

    return choice;
}


int main(){

    

    int choice;

    while((choice = menu()) !=0){
        switch(choice){
            case 1: {
                Volume V1;
                cout<<"Volume by default values: "<<V1.calculateVolume()<<endl;
                break;
            }

            case 2: {
                
                int value;
                cout<<"Enter value: "<<endl;
                cin>>value;
                Volume V2(value);
                cout<<"Volume with same value: "<<V2.calculateVolume()<<endl;
                break;
            }

            case 3: {
               
                int l,w,h;
                cout<<"Enter l,w,h : "<<endl;
                cin>>l>>w>>h;
                Volume V3(l,w,h);
                cout<<"Volume with diff values: "<<V3.calculateVolume()<<endl;
                break;
            }

            default:
                cout<<"Invalid choice "<<endl;
                break;


            
        }
    }
    return 0;
}