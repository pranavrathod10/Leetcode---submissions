class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for(int i=0;i<=(m+n-2);i++){
            vector<int> temp = mp[i];
            // for(auto val: temp){
            //     cout<<val<<" "<<endl;
            // }
            if(i%2 == 0){
                for(int j=temp.size()-1;j>=0;j--){
                    ans.push_back(temp[j]);
                }
            }
            else{
                for(int j=0;j<temp.size();j++){
                    ans.push_back(temp[j]);
                }
            }
        }
        return ans;
    }
};