#include <iostream>

// @Esmail-Mohamed

using namespace std;


template<typename T>
class Queue{
    int front;
    int back;
    int length;
    int maxSize;
    T *arr;
public:
    Queue(int size){
        maxSize=size;
        front=0;
        length=0;
        back=size-1;
        arr=new T[size];
    }

    bool empty(){
        return !length;
    }

    bool full(){
        return length==maxSize;
    }

    void push(T element){
        if(full()){
            cout<<"no available space to add new element:(\n";
        }
        else{
            back=(back+1)%maxSize;
            arr[back]=element;
            length++;
        }
    }
    void pop(){
        if(empty()){
            cout<<"no available element to remove :) \n";
        }
        else{
            length--;
            front=(front+1)%maxSize;
        }
    }

    void getFront(){
        if(empty()){
            cout<<"The queue is empty \n";
            return;
        }
        cout<< arr[front]<<endl;
    }

    void getBack(){
        if(empty()){
            cout<<"The queue is empty \n";
            return;
        }
        cout<<arr[back]<<endl;
    }
    void print(){
        if(empty()){
            cout<<"The queue is empty so cannot printed :(\n";
            return;
        }
        cout<<'[';
        for(int i=front;i!=back;i=(i+1)%maxSize){
            cout<<arr[i]<<",";
        }
        cout<<arr[back]<<"]\n";
    }
    ~Queue(){delete []arr;}
};

int main() {
    Queue<int>q(5);
    q.getFront();// The queue is empty;
    q.push(50);
    q.push(8);
    q.push(46);
    q.getFront(); //50
    q.getBack();//46
    q.push(7);
    q.pop();// remove 50
    q.print();//[50,8,46]

}
