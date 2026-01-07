class Solution {
public:
    int func(vector<int>& coins, int amount,vector<int>& memo){
        if(amount == 0){
            return 0;
        }
        else if(amount < 0){
            return 1e7;
        }
        if(memo[amount] != -1){
            return memo[amount];
        }
        int ans = INT_MAX;
        for(int i=0;i<coins.size();i++){
            ans = min( ans , 1 + func(coins, amount - coins[i], memo));
        }
        memo[amount] = ans;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, -1);
        int ans = func(coins, amount, memo);
        return ans > amount ? -1: ans;
        // memo[0] = 0;
        // for(int coin: coins){
            
        // }

    }
};