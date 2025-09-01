#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;

    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;

    }

};

int main(){
    vector<int> arr = {0,1,2,3};
    Node* y = new Node(arr[3]);

    cout<< y->data << endl;

}