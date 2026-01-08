class Solution {
    vector<int> memo = vector<int>(59, -1);
public:
    
    int integerBreak(int n) {
        if(n == 2 || n == 1){
            return 1;
        }
        if(memo[n] != -1){
            return memo[n];
        }
        int ans = 1;
        for(int i=1;i<n;i++){
            ans = max(ans, i*integerBreak(n-i));
            ans = max(ans, i*(n-i));
        }
        memo[n] = ans;
        return ans;
    }
};