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
    if(arr.empty())return nullptr;
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

// Node* InsertHead(Node* head, int val){
//     Node* temp = new Node(val, head);
//     return temp;
// }

// Node* InsertLast(Node*head , int val){
//     if(head == NULL){
//         return new Node(val);
//     }
//     Node* temp = head;
//     while(temp->next != NULL){
//         temp = temp->next;
//     }
//     Node* last = new Node(val);
//     temp->next = last;
//     return head;
    
// }
// Node* InsertAtPos(Node* head, int k , int val){
//     if(head == NULL){
//         if(k == 1){
//             return new Node(val);
//         }
//         else{
//             return NULL;
//         }
//     }
//     if(k == 1){
//         Node* temp = new Node(val, head);
//         return temp;
//     }
//     int cnt = 0;
//     Node* temp = head;
//     while(temp){
//         cnt++;
//         if(cnt == k-1){
//             Node* x = new Node(val);
//             x->next = temp->next;
//             temp->next = x;
//             break;
//         }
//         temp = temp->next;
//     }
//     return head;
// }
Node* InsertBeforeVal(Node* head, int el , int val){
    if(head == NULL){
        return  NULL;
    }
    if(head->data == val){
        Node* temp = new Node(el, head);
        return temp;
    }

    Node* temp = head;
    while(temp->next != NULL){
        
        if(temp->next->data == val){
            Node* x = new Node(el,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {46, 32, 52, 73, 22};
    Node* head = arraytoLL(arr);
    // head = InsertHead(head, 28);
    // head = InsertLast(head, 35);
    // head = InsertAtPos(head, 1, 35);
    head = InsertBeforeVal(head, 34, 22);
    print(head);

}