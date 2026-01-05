class Solution {
public:
    int func(int n, vector<int>& memo){
        if(n==1){
            memo[1] = 1;
            return 1;
        }
        if(n==2){
            memo[2] = 2;
            return 2;
        }

        if(memo[n] != 0){
            return memo[n];
        }

        int ans  = 0;
        for(int i=1;i<=2;i++){
            ans += func(n-i,memo);
        }
        memo[n] = ans;
        return ans;
    }
    int climbStairs(int n) {
        vector<int> memo(n+1,0);
        return func(n,memo);
        
    }
};