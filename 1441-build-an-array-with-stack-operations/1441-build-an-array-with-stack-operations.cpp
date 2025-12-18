class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // stack<int> st;
        vector<string> ans;
        int j = 0;
        for(int i=1;i<=n;i++){
            if(j == target.size()){
                break;
            }
            ans.push_back("Push");
            if(j<target.size() && target[j] != i){
                ans.push_back("Pop");

            }
            else{
                j++;
            }
            
            
        }

        return ans;
    }
};