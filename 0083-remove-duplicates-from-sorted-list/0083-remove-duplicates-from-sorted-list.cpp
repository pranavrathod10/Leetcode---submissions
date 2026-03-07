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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> map;
        ListNode* temp = head;
        if(head == nullptr){
            return head;
        }
        map[temp->val]++;
        while(temp->next){
            int x = temp->next->val;

            map[x]++;
            // cout<<x<<" "<<map[x]<<endl;
            if(map[x]>1){
                // cout<<"if "<<x<<endl;
                temp->next = temp->next->next;
                map[x]--;
            }
            else{
                // cout<<" else "<<x<<endl;
                temp = temp->next;
            }
            
        }
        return head;
    }
};