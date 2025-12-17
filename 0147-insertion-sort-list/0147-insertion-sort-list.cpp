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
    void func(int value,ListNode* head ){
        ListNode* temp = head;
        
        // bool flag = false;
        // if(temp->val >= value){
        //     ListNode* newHead = new ListNode(value);
        //     newHead->next = head;
        //     return ;
        // }

        while(temp != nullptr){
            if(temp->val < value){
                if( temp->next != nullptr && temp->next->val >= value){
                    // flag = true;
                    // cout<<"in bet"<<endl;
                    ListNode* nextNode = temp->next;
                    temp->next = new ListNode(value);
                    temp = temp->next;
                    temp->next = nextNode;
                }
                else if(temp->next == nullptr){
                    // cout<<"at end"<<endl;
                    temp->next = new ListNode(value);
                    // temp
                }
                
            }
            temp = temp->next;
        }
        

        return ;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode(head->val);
        head = head->next;
        // cout<<"hii"<<endl;
        while(head != nullptr){
            int value = head->val;
            // cout<<value<<endl;
            // cout<<"newhead val"<<newHead->val<<endl;
            if(newHead->val >= value){
                // cout<<"here if"<<endl;
                ListNode* temp = new ListNode(value);
                temp->next = newHead;
                newHead = temp;
            }
            else{
                // cout<<"here else"<<endl;
                func(value,newHead);
            }
            head = head->next;
            // cout<<"newhead val"<<newHead->val<<endl;
            // cout<<"-----"<<endl;
        }

        return newHead;
    }
};