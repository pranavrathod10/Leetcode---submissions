class Solution {
public:
    int func(int sum,int n,vector<vector<int>>& memo,vector<int>& nums,int tar,int offset){
        if(sum == tar && n==0){
            // memo[n][sum+ offset] = 1;
            return 1;
        }
        else if(n == 0){
            // memo[n][sum+ offset] = 0;
            return 0;
        }

        if(memo[n][sum+ offset] != -1){
            return memo[n][sum+ offset];
        }

        // int in = 0, out = 0;
        memo[n][sum+ offset] = func(sum+nums[n-1],n-1,memo,nums,tar,offset) + func(sum-nums[n-1],n-1,memo,nums,tar,offset);

        return memo[n][sum+ offset];

    }
    int findTargetSumWays(vector<int>& nums, int tar) {
        int n = nums.size();
        int sum = 0;
        for(int x: nums){
            sum += x;
        }
        vector<vector<int>> memo(n+1,vector<int>(2*sum+1,-1));
        return func(0,n,memo,nums,tar,sum);
    }
};