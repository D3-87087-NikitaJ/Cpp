/*Q3. Stack is a Last-In-First-Out data structure. 
Write a Stack class that stores int type of data. It 
implements stack using Dynamically allocated array. 
Stack size should be passed in parameterized 
constructor. If size is not given, allocate stack of size 5.
Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print()*/

#include<iostream>
using namespace std;

class Stack{
    int top;
    int size;
    int *ptr;

public:
    Stack(){
        top=-1;
        this->size=5;
        ptr = new int[this->size];
    }

    Stack(int size){
        top =-1;
        this->size = size;
        ptr = new int[this->size];
    }

    void push(int value){
        if(isFull()){
            cout<<"Stack full. Cant push."<<endl;
        }
        else{
            top++;
            ptr[top]=value;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack empty. Can't pop."<<endl;
        }
        else{
            cout<<"pop : "<<ptr[top]<<endl;
            top--;
        }
    }

    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
        }
        else{
            return ptr[top];
        }
    }

    bool isFull(){
        if(top==(size-1)){
            return true;
        }
        else{
            return false;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void printStack(){
        if(isEmpty()){
            cout<<"Empty Stack."<<endl;
        }
        else{
            cout<<"Stack: "<<endl;
            for(int i=0;i<=top;i++){
                cout<<ptr[i]<<" "<<endl;

            }
        }
    }

    ~Stack(){
        delete[] ptr;
        ptr= NULL;
    }
    };

    int menu(){
        int choice;
        cout<<"0. EXIT"<<endl;
        cout<<"1. PUSH"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. isEmpty"<<endl;
        cout<<"5. isFull"<<endl;
        cout<<"6. Print Stack"<<endl;
        cout<<" Enter choice: "<<endl;
        cin>>choice;
        return choice;

    }

int main(){

    Stack s1(5);
    int ch;
    int num;
    
    while((ch=menu())!=0){
        switch(ch){
            case 1: 
                cout<<"Enter: "<<endl;
                cin>>num;
                s1.push(num);
                break;

            case 2:
                cout<<"Pop: "<<endl;
                s1.pop();
                break;

            case 3:
                cout<<"Peek: "<<endl;
                cout<<s1.peek()<<endl;
                break;

            case 4:
                if(s1.isEmpty()){
                    cout<<"Stack is empty"<<endl;

                }
                else{
                    cout<<"Stack is not empty"<<endl;
                }
                break;

            case 5:
                if(s1.isFull()){
                    cout<<"Stack is full"<<endl;
                }
                else{
                    cout<<"Stack is not full"<<endl;
                }
                break;

            case 6:
                
                s1.printStack();
                break;

            default:
                cout<<"Invalid choice"<<endl;
                break;

        }

    }

   


    return 0;
}




