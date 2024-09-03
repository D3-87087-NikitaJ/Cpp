/*Q1. Write a class to find volume of a Cylinder by using following members. 
(volume of Cylinder=3.14 * radius * radius *height) ( use static wherever needed. hint-PI)
Class having following member functions:
Cylinder()
Cylinder(double radius, double height)
getRadius()
setRadius()
getHeight()
setHeight()
calculateVolume()
Initialize members using constructor member initializer list*/

#include<iostream>
using namespace std;

class Cylinder{
    double radius;
    double height;
    static double const PI;

public:
    Cylinder() : radius(2), height(3)
    {

    }

    Cylinder(double radius, double height) : radius(radius),height(height)
    {

    }

    double getRadius(){
        return radius;
    }

    void setRadius(double r){
        radius = r;
    }

    double getHeight(){
        return height;
    }

    void setHeight(double h){
        height = h;
    }

    double calculateVolume(){
        float vol = PI*radius*radius*height;
        cout<<"Volume of Cylinder is "<<vol<<"meter cube."<<endl;
    }
    


};

double const Cylinder::PI = 3.14;

int main(){
    Cylinder c1;
    c1.calculateVolume();
    Cylinder c2(3,2);
    c2.calculateVolume();

    return 0;
}