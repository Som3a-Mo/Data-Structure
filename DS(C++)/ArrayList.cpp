#include <iostream>

// @Esmail-Mohamed

using namespace std;


template<typename T>
class ArrayList{
    T *arr;
    int length;
    int maxSize;
public:
    ArrayList(int size){
        size=abs(size);
        length=0;
        maxSize=size;
        arr=new T[size];
    }

    bool empty(){
        return !length;
    }

    bool full(){
        return length==maxSize;
    }

    void print(){
        if(empty()){
            cout<<"There is no element to print ! \n";
            return;
        }
        cout<<'[';
        for(int i=0;i<length;i++){
            cout<<arr[i]<<(i==length-1?"]\n":",");
        }
    }

    void insertAtPos(T element,int pos){
        if(full()){
            cout<<"The array is full\n";
        }else if(pos<0||pos>length){
            cout<<"Out of range \n";
        }
        else{
            for(int i=length;i>pos;i--){
                arr[i]=arr[i-1];
            }
            arr[pos]=element;
            length++;
        }
    }
    void insertBack(T element){
        if(full()){
            cout<<"The array is full\n";
        }else{
            arr[length]=element;
            length++;
        }
    }

    int search(T element){
        for(int i=0;i<length;i++){
            if(arr[i]==element){
                return i;
            }
        }
        return -1;
    }

    void removeAtPos(int pos){
        if(empty()){
            cout<<"The array is empty\n";
        }else if(pos<0||pos>length){
            cout<<"Out of range\n";
        }else{
            for(int i=pos;i<length;i++){
                arr[i]=arr[i+1];
            }
            length--;
        }
    }
    int size(){
        return length;
    }
};

int main() {
    ArrayList<int>arrayList(5); // create array list with size 5
    arrayList.insertBack(8); 
    arrayList.insertBack(7);
    arrayList.print(); // [8,7]
    arrayList.insertAtPos(6,1);
    arrayList.removeAtPos(2);//remove 7
    arrayList.print(); // [8,6]
    cout<<arrayList.size(); // 2
}
