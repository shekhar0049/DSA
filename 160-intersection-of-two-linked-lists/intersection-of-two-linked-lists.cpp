/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        int c1=0,c2=0;
        ListNode*t1=h1,*t2=h2;
        while(t1->next!=NULL){
            t1=t1->next;
            c1++;
        }
         while(t2->next!=NULL){
            t2=t2->next;
            c2++;
        }
       if(c1>c2){
        while(c1>c2){
            h1=h1->next;
            c1--;
        }
        }
        else{
            while(c1<c2){
            h2=h2->next;
            c2--;
        }
        }

       while(h1!= h2){
        h1=h1->next;
        h2=h2->next;
       }
       return h1;
        
    }
};