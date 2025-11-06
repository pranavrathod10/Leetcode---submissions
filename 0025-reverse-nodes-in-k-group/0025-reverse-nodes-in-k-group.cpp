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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        ListNode* temp = head;
        stack<ListNode*> st;

        int kk = k;
        while(kk && temp != nullptr){
            st.push(temp);
            temp = temp->next;
            kk--;
        }
        if(kk>0){
            return head;
        }
        ListNode* nextt = temp;
        ListNode* newStart = st.top();
        temp = newStart;
        st.pop();
        kk = k-1;
        while(!st.empty()){
            temp->next = st.top();
            st.pop();
            temp = temp->next;
        }
        temp->next = reverseKGroup(nextt,k);
        return newStart;
    }
};