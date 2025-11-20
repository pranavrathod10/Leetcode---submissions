class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int kk = k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(kk>0){
                
                kk--;
            }
            else{
                pq.pop();
            }
        }
        return pq.top();
    }
};