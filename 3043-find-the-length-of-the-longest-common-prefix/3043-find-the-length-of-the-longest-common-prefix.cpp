class Solution {
public:
    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();

        int ans = 0;

        unordered_map<string,bool> mp;
        for(auto it: a){
            string s = to_string(it);
            for(int i = s.length();i>0;i--){
                mp[s.substr(0,i)] = true;
            }
        }
        sort(b.begin(),b.end(),greater<int>());
        for(auto it: b){
            string sb = to_string(it);
            if(sb.length() <= ans){
                break;
            }
            for(int i=sb.length();i>0;i--){
                if(mp[sb.substr(0,i)]){
                    ans = max(ans,i);
                    break;
                }
            }
        }
        return ans;
    }
};