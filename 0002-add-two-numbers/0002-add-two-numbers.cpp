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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* head = nullptr;
        ListNode* temp = head;
        int carry = 0;
        while ( p1 || p2){

            int sum = carry;
            if(p1){
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2){
                sum+= p2->val;
                p2 = p2->next;
            }

            ListNode* newNode = new ListNode();
            if (sum < 10){
                newNode->val = sum;
                carry = 0;
            }
            else{
                newNode->val = sum - 10;
                carry = 1;
            }
            if(head == nullptr){
                head = newNode;
                temp = head;
            }
            else{
                temp->next = newNode;
                temp = temp->next;
            }
            
        }
        if ( carry == 1){
            temp->next = new ListNode(1);
        }
        return head;
    }
};