class Solution {
    vector<int> memo;
public:
    int func(vector<int>& nums, int target){
        // if(idx >= nums.size()){
        //     return target == 0? 1: 0;
        // }
        // else if()
        if(target == 0){
            return 1;
        }
        
        if(memo[target] != -1){
            return memo[target];
        }

        int ans = 0;
        for(int x: nums){
            if(target - x >= 0){
                ans += func(nums, target - x);
                // ans += func(nums, target, idx+1);
            }
        }
        
        memo[target] = ans;
        return ans;

    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        memo.resize(target+1,-1);
        return func(nums,target);
    }
};