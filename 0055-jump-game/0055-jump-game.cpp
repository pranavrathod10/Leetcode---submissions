class Solution {
public:
    bool solve(vector<int>& nums,int idx,int n,vector<int>& memo){
        if(idx > n-1){
            return true;
        }
        if(idx == n-1){
            memo[idx] = 1;
            return true;
        }

        if(nums[idx] == 0){
            memo[idx] = 0;
            return false;
        }

        if(memo[idx] != -1){
            if(memo[idx] == 0){
                return false;
            }
            return true;
        }

        

        int len = nums[idx];
        while(len>0){
            if(solve(nums,idx+len,n,memo)){
                memo[idx] = true;
                return true;
            }
            len--;
        }
        memo[idx] = false;

        return false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return true;
        }
        vector<int> memo(n,-1);
        return solve(nums,0,n,memo);
    }
};