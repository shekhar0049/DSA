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
Node* arraytoLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover-> next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<< head->data << " ";
        head = head->next;
    }
}

Node* InsertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

// Node* InsertLast(Node*head , int val){
//     Node* temp = head;
//     while(temp != NULL){
//         if(temp->next == NULL){
//             Node* last = new Node(val);
//             temp-> next = last;
//         }
//     }
//     return head;
    
// }

int main(){
    vector<int> arr = {1,4,7,2,5};
    Node* head = arraytoLL(arr);
    head = InsertHead(head, 28);
    // head = InsertLast(head, 35);
    print(head);

}