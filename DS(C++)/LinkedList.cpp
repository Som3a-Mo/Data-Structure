#include <iostream>

// @Esmail-Mohamed

using namespace std;


template<typename T>
class LinkedList{
    class Node{
    public:
        T item;
        Node*next;
    };
    Node *head,*tail;
    int length;
public:
    LinkedList(){
        head=tail=NULL;
        length=0;
    }

    bool empty(){
        return !length;
    }

    void emptyMessage(){
        cout<<"There is no element\n";
    }

    int size(){
        return length;
    }

    void addFirst(T element){
        Node*newNode=new Node;
        newNode->item=element;
        if(empty()){
            head=tail=newNode;
            newNode->next=NULL;
        }else{
            newNode->next=head;
            head=newNode;
        }
        length++;
    }

    void addLast(T element){
        Node*newNode=new Node;
        newNode->item=element;
        if(empty()){
            head=tail=newNode;
            newNode->next=NULL;
        }else{
            tail->next=newNode;
            newNode->next=NULL;
            tail=newNode;
        }
        length++;
    }
    void addAtPos(int pos,T element){
        if(pos==0){
            addFirst(element);
        }else if(pos==length){
            addLast(element);
        }else if(pos<0||pos>length){
            cout<<"Out of range\n";
        }else{
            Node*newNode=new Node;
            newNode->item=element;
            Node*temp=head;
            for(int i=1;i<pos;i++){
                temp=temp->next;
            }
            newNode->next=temp->next;
            temp->next=newNode;
            length++;
        }
    }

    void removeFirst(){
        if(empty()){
            emptyMessage();
        }
        else if(length==1){
            head=tail=NULL;
            length--;
        }
        else {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            length--;
            delete temp;
        }
    }
    void removeLast(){
        if(empty()){
            emptyMessage();
        }
        else if(length==1){
            head=tail=NULL;
            length--;
        }
        else {
            Node *temp = head;
            while (temp->next != tail)
                temp = temp->next;
            tail=temp;
            temp= temp->next;
            delete temp;
            tail->next = NULL;
            length--;
        }
    }
    void remove(T element){
        if(empty()){
            emptyMessage();
        }else if(head->item==element){
            removeFirst();
        }else{
            Node *prev=head,*cur=head->next;
            while(cur!=NULL){
                if(cur->item==element) {
                    break;
                }
                prev=cur;
                cur=cur->next;
            }
            if(cur==NULL){
                cout<<"The element not found\n";
            }
            else{
                prev->next=cur->next;
                if(cur==tail)
                    tail=prev;
                delete cur;
                length--;
            }
        }
    }
    void print(){
        if(empty()){
            emptyMessage();
            return;
        }
        Node*temp=head;
        cout<<'[';
        while(temp!=NULL){
            cout<<temp->item;
            temp= temp->next;
            cout<<(temp!=NULL?",":"]\n");
        }
    }
};

int main() {
    LinkedList<int>l;
    l.addLast(5);//[5]
    l.addLast(3);//[5,3]
    l.addAtPos(1,0);//[5,0,3]
    l.addFirst(-1);//[-1,5,0,3]
    l.removeFirst();//[5,0,3]
    l.removeLast();//[5,0]
    l.remove(0);//[5]
    l.print();// [5]
}
