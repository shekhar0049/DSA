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

Node* arr2dll(vector<int>arr){
    if(arr.empty())return NULL;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1 ; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(Node *head){
    while(head != NULL){
        cout<< head->data << " ";
        head = head->next;
    }
}

Node* insertBeforeHead(Node* head, int val){
    if(head == NULL)return new Node(val, nullptr, nullptr);
    Node* newHead = new Node(val,head,nullptr);
    head->back = newHead;
    return newHead;
}
Node* insertBeforeTail(Node* head, int val){
    if(head == NULL)return new Node(val, nullptr, nullptr);
    if(head->next == NULL){
      Node* tail = new Node(val, head, nullptr);
      head->back = tail;
      return tail;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* tail = new Node(val, temp->next, temp);
    temp->next = tail;
    tail->next->back = tail;
    return head;

}

Node* insertBeforeKth(Node* head, int k, int val){
    if(k==1)return insertBeforeHead(head, val);
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt == k)break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* Kth = new Node(val, temp, prev);
    prev->next = temp->back = Kth;
    return head;

}

int main(){
    vector<int> arr = {5,8,12,4,3};
    Node* head = arr2dll(arr);
    head = insertBeforeKth(head , 5, 22);
    print(head);

return 0;
}