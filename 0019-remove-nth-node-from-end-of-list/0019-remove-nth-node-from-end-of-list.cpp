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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1  = head;
        // if (n==1){

        // }
        while(p1 && n){
            p1 = p1->next;
            n--;
        }
        if ( p1 == nullptr){
            head = head->next;
            return head;
        }
        // cout<<p1->val<<endl;
        ListNode* temp = head;
        while ( p1->next){
            p1 = p1->next;
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return head;
    }
};