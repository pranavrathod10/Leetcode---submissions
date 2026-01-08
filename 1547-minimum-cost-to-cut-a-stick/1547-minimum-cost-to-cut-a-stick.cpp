class Solution {
    unordered_map<long long,int> memo;
public:
    int func( vector<int>& cuts, int l, int r){
        if(r-l <= 1){
            // memo[{l,r}] = 0;
            return 0;
        }
        long long key = (long long)l << 32 | r;
        if(memo.count(key) > 0){
            return memo[key];
        }
        int cost = INT_MAX;
        for(int idx: cuts){
            // int idx = cuts[i];
            if(idx>l && idx<r){
                cost = min( cost , r-l + func(cuts,l,idx) + func(cuts,idx,r) );
            }
        }
        memo[key] = cost == INT_MAX? 0: cost;
        return memo[key];
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        // vector<vector<int>> memo(n+1, vector<int>(n+1,-1));

        return func(cuts,0,n);
    }

};