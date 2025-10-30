class Solution {
public:
    int func(vector<int>& nums, int n, int tar,unordered_map<int,int>& memo){
        if(memo.count(tar)>0){
            return memo[tar];
        }
        if(tar == 0){
            memo[tar] = 1;
            return 1;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(tar >= nums[i]){
                ans += func(nums,n,tar - nums[i],memo);
            }
        }
        memo[tar] = ans;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int tar) {
        int n = nums.size();
        unordered_map<int,int> memo;
        return func(nums,n,tar,memo);

    }
};