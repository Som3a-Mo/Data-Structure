#include <iostream>

// @Esmail-Mohamed

using namespace std;

const int MAX_STACK_SIZE=1000;

template<typename T>
class stack{
    int top;
    T stackArray[MAX_STACK_SIZE];
public:
    stack(){
       top=-1;
    }

    bool empty(){
        return top<0;
    }

    bool full(){
        return top==MAX_STACK_SIZE-1;
    }

    void push(T element){
        if(full()){
            cout<<"The stack is full :( \n ";
        }
        else {
            stackArray[++top]=element;
        }
    }
    
    void pop(){
        if(empty()){
            cout<<"The stack is empty :( \n";
        }
        else {
            --top;
        }
    }

    void Top(){
        if(empty()){
            cout<<"The stack is empty :( \n";
        }
        else {
            cout<<stackArray[top]<<endl;
        }
    }

    void print(){
        if(empty()) {
            cout << "The stack is empty !\n";
        }else {
            cout << '[';
            for (int i = top; i >= 0; i--) {
                cout << stackArray[i] << (i > 0 ? ", " : "");
            }
            cout << "]\n";
        }
    }
};

int main() {
    stack<int>s;
    s.push(8);
    s.push(46);
    s.push(-8);
    s.print();// [-8, 46, 8]
    s.pop(); // remove -8
    s.Top();// 46
}
