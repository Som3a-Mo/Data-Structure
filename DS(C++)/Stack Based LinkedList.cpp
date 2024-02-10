#include <iostream>

// @Esmail-Mohamed

using namespace std;


template<typename T>
class Stack{
    class Node{
    public:
        T item;
        Node*next;
    };
    Node*top;
public:
    Stack(){
        top=NULL;
    }

    bool empty(){
        return top==NULL;
    }
    
    void push(T element){
        Node*newNode=new Node;
        if(!newNode){
            cout<<"Stack overFlow :(\n";
            return;
        }
        newNode->item=element;
        newNode->next=top;
        top=newNode;
    }

    void pop(){
        if(empty()){
            cout<<"The stack is empty :) \n";
        }else{
            Node*temp=top;
            top=top->next;
            temp->next=NULL;
            delete temp;
        }
    }

    void Top(){
        if(empty()){
            cout<<"The Top is NULL :(\n";
        }else{
            cout<<top->item<<endl;
        }
    }

    void print(){
        Node*temp=top;
        cout<<'[';
        while(temp!=NULL){
            cout<<temp->item;
            temp=temp->next;
            cout<<(temp!=NULL?",":"");
        }
        cout<<"]\n";
    }
};

int main() {
    Stack<int>s;
    s.push(5);
    s.push(9);
    s.push(7);
    s.Top();// 7
    s.pop();// remove 7
    s.Top();// 9
    s.print();// [9,5]
}
