class Solution {
public:
    string reverse_str(string& s){
        string res = "";
        for(int i=s.length()-1;i>=0;i--){
            res += s[i];
        }
        return res;
    }
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string,int> mp;
        int ans = 0;
        for(int i=0;i<words.size();i++){
            string curr = words[i];
            mp[curr] = i;
            if(mp.count(reverse_str(curr))>0 && mp[reverse_str(curr)] < i){
                ans++;
            }
        } 
        return ans;
    }
};