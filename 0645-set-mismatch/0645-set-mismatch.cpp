class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,0);
        // sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=1;i<=n;i++){
            if(nums[i-1] != i){
                ans[0] = nums[i-1];
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};