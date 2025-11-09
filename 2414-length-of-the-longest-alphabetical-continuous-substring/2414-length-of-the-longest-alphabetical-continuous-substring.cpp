class Solution {
public:
    int Val(char ch){
        return ch - 'a';
    }
    int longestContinuousSubstring(string s) {
        int n = s.length();
        int l=0,r=1;
        int res = 1;
        while(r<n){
            if(r<n && Val(s[r]) - Val(s[l]) == 1){
                int diff = 1;
                while(Val(s[r]) - Val(s[l]) == diff){
                    r++;
                    diff++;
                }
                res = max(res, r-l);
                l = r;
                r++;
            }
            else{
                l++;r++;
            }
        }

        return res;
    }
};