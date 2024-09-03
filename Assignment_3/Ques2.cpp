/*Q2. Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
In main create array of objects of Time.
Allocate the memory for the array and the object dynamically.*/

#include<iostream>
using namespace std;

class Time{
    int hrs;
    int mins;
    int sec;

public:
    Time() : hrs(3), mins(6), sec(9){

    }

    Time(int hrs, int mins, int sec): hrs(hrs), mins(mins), sec(sec){

    }

    int getHours(){
        return hrs;
    }

    void setHours(int h ){
        hrs=h;
    }

    int getMinutes(){
        return mins;
    }

    void setMinutes(int m ){
        mins=m;
    }

    int getSeconds(){
        return sec;
    }

    void setSeconds(int s ){
        sec =s;
    }

    void display(){
        cout<<"Time = "<<hrs<<":"<<mins<<":"<<sec<<endl;
    }

};

int main(){
    //allocating dynamic memory to both array and object
    //dynamic memory on heap
    Time **t= new Time *[3];

    t[0] = new Time();
    t[0]->display();
    t[0]->setHours(2);
    t[0]->setMinutes(22);
    t[0]->setSeconds(44);
    t[0]->getHours();
    t[0]->getMinutes();
    t[0]->getSeconds();
    t[0]->display();

    t[1] = new Time(4,55,34);
    t[1]->display();



    

    return 0;
}