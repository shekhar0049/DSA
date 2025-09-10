#include<iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* arr2dll(vector<int> arr){
    if(arr.empty())return NULL;

    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node* head){
    while(head != NULL){
        cout<< head->data << " ";
        head = head->next;
    }
}

// Node* DeleteHead(Node* head){
//     if(head == NULL || head->next == NULL)return NULL;
//     Node* temp = head;
//     head = head->next;
//     head->back = nullptr;
//     temp->next = nullptr;
//     delete temp;
//     return head;
// }

// Node* DeleteTail(Node* head){
//     if(head == NULL || head->next == NULL)return NULL;
//     Node* temp = head;
    
//     while(temp){
//         if(temp->next == NULL){
//             Node* prev = temp->back;
//             temp->back = NULL;
//             prev->next = NULL;
//             free(temp);
//         }
//         temp = temp->next;
//     }
//     return head;
// }

// Node* DeleteKth(Node* head , int k){
//     if(head == NULL)return NULL;
//     Node* temp = head;
//     int cnt = 0;
//     while(temp){
//        cnt ++;
//        if(cnt == k)break;
//        temp = temp->next;   
//     }
//     Node* prev = temp->back;
//     Node* Next = temp->next;

//     if(prev == NULL && Next == NULL){
//         return NULL;
//     }
//     else if(prev == NULL){
//         return DeleteHead(head);
//     }
//     else if(Next == NULL){
//         return DeleteTail(head);
//     }
//     prev->next = Next;
//     Next->back = prev;
//     temp->next = nullptr;
//     temp->back = nullptr;
//     free(temp);
//     return head;
// }

void DeleteNode(Node* temp){
    Node* prev = temp->back;
    Node* Next = temp->next;

    if(Next == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = Next;
    Next->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);

}
int main(){
    vector<int> arr ={3,7,1,0,9};
    Node* head = arr2dll(arr);
    // head = DeleteHead(head); 
    // head = DeleteTail(head);
    // head = DeleteKth(head, 1);
    DeleteNode(head->next->next);
    print(head);

}