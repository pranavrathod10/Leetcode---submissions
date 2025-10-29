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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pts;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        int idx=0;
        int min_dis = INT_MAX;
        while(ptr2 != nullptr){
            ListNode* ptr3 = ptr2->next;
            if(ptr3 != nullptr){
                int val1 = ptr1->val;
                int val2 = ptr2->val;
                int val3 = ptr3->val;
                // cout<<val1<<val2<<val3<<endl;
                if(val2>val1 && val2>val3){
                    pts.push_back(idx);
                    // idx++;
                }
                else if(val2<val1 && val2<val3){
                    pts.push_back(idx);
                    
                }
                if(pts.size()>=2){
                    int n = pts.size();
                    min_dis = min(min_dis , pts[n-1] - pts[n-2]);
                }
                
                ptr1 = ptr2;
                ptr2 = ptr2->next;
                idx++;
            }
            else{
                break;
            }
            
        }
        if(pts.size()<2){
            return {-1,-1};
        }

        return {min_dis,pts[pts.size()-1]-pts[0]};

        
    }
};