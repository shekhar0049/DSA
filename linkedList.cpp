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
           mover->next = temp;
           mover = temp;
        
    }
    return head;
}

int lengthofLL(Node* head){
    int count = 0; 
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;

}
// bool searchinLL(Node* head, int key){
//     Node* temp = head;
//     while(temp){
//         if(temp->data == key){
//             return 1;
//         }
//     }
//     return 0;
//}
int main(){
    vector<int> arr = {15,1,2,3};
    int count;
    Node* head = arraytoLL(arr);
    Node* temp = head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
//     bool ans;
//  ans =searchinLL(head, 2);
    count = lengthofLL(head);
    cout << endl << count << endl;
    // cout << endl << ans << endl;

}