class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        int ans = 0;
        for(auto row: matrix){
            string pat = "";
            for(int j =0;j<matrix[0].size();j++){
                pat += (row[0]==row[j])?1:0;
            }
            mp[pat]++;
            ans = max(ans, mp[pat]);
        }
        return ans;
    }
};