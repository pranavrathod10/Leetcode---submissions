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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        cout<<"-------1"<<endl;
        // ListNode* temp = head;
        while(head != nullptr ){
            if(mp.count(head->val)>0){
                head = head->next;
            }
            else{
                break;
            }

        }
        cout<<"-------2"<<endl;
        if(head == nullptr){
            return head;
        }

        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        cout<<"head val -- "<<head->val<<endl;

        while(ptr1 != nullptr){
            if(ptr2!= nullptr && mp[ptr2->val]){
                ptr1->next = ptr2->next;
                if(ptr2->next == nullptr){
                    return head;
                }
                else{
                    ptr2 =  ptr1->next;
                }

            }
            else if(ptr2 == nullptr){
                return head;
            }
            else{
                ptr1 = ptr2;
                if(ptr2->next == nullptr){
                    ptr2 = nullptr;
                }
                else{
                    ptr2 = ptr2->next;
                }
                
            }

        }


        return head;
    }
};