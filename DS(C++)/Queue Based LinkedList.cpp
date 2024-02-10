#include <iostream>

// @Esmail-Mohamed

using namespace std;


template<typename T>
class Queue{
    class Node{
    public:
        T item;
        Node*next;
        Node():next(NULL){}
    };

    int length;
    Node *front,*back;
public:
    Queue(){
        front=NULL;
        back=NULL;
        length=0;
    }

    bool empty(){
        return !length;
    }

    int size(){
        return length;
    }

    void push(T element){
        Node*newNode=new Node;
        newNode->item=element;

        if(empty()){
            front=back=newNode;
            length++;
            return;
        }
        back->next=newNode;
        back=newNode;
        length++;
    }

    void pop(){
        if(empty()){
            cout<<"no element in queue to remove \n";
        }
        else{
            Node*temp=front;
            front= front->next;
            temp->next=NULL;
            delete temp;
            length--;
        }
    }

    T getFront(){
        if(empty()){
            cout<<"Queue is empty\n";
            return NULL;
        }
        return front->item;
    }

    T getBack(){
        if(empty()) {
            cout << "Queue is empty\n";
            return NULL;
        }
        return back->item;
    }

    void print(){
        Node*temp=front;
        cout<<'[';
        while(temp!=NULL){
            cout<<temp->item;
            temp= temp->next;
            if(temp!=NULL)
                cout<<",";
            else cout<<"]\n";
        }
    }
};

int main() {
    Queue<int>q;
    q.push(8);
    q.push(78);
    q.push(-56);
    q.print();// [8,78,-56]
    cout<<q.size()<<endl;// 3
    
}
