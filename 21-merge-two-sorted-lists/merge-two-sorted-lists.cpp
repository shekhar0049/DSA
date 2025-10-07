/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* newNode = new ListNode(-101);
        ListNode* temp3 = newNode;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val < temp2->val){
                ListNode* x = new ListNode(temp1->val);
                temp3->next = x;
                temp3 = x;
                temp1 = temp1->next;
            }
            else if(temp1->val > temp2->val){
                ListNode* x = new ListNode(temp2->val);
                temp3->next = x;
                temp3 = x;
                temp2 = temp2->next;    
            }
            else{
                ListNode* x = new ListNode(temp1->val);
                temp3->next = x;
                temp3 = x;
                ListNode* y = new ListNode(temp2->val);
                temp3->next = y;
                temp3 = y;

                temp1 = temp1->next;
                temp2 = temp2->next; 
            }
        }
        while(temp1 != NULL){
            ListNode* x = new ListNode(temp1->val);
            temp3->next = x;
            temp3 = x;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            ListNode* x = new ListNode(temp2->val);
            temp3->next = x;
            temp3 = x;
            temp2 = temp2->next;
        }

        return newNode->next;
        
    }
};