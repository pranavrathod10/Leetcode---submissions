class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        for(auto q: queries){
            for(int i=q[0];i<=q[2];i++){
                for(int j=q[1];j<=q[3];j++){
                    ans[i][j] += 1;
                }
            }
        }
        return ans;
    }
};