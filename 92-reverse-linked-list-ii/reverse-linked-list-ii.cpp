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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> st;
        if(left == right)return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int cnt1 = 1; 
        int cnt2 = 1;

        while(cnt1 < left){
            cnt1++;
            temp1 = temp1->next;    
        }
        while(cnt2 < right){
            cnt2++;
            temp2 = temp2->next;
        }
        ListNode* x = temp1;
        while(x != temp2->next){
            st.push(x->val);
            x = x->next;
        }
        x = temp1;
        while(!st.empty()){
            x->val = st.top();
            st.pop();
            x = x->next;
        }
        return head;

        
    }
};