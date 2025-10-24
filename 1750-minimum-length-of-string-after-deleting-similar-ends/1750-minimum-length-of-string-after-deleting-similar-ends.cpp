class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        while(l<r){
            if(s[l] == s[r]){
                char ch = s[r];
                while(s[l]==ch && l<=r && l<n){
                    l++;
                }
                while(s[r] == ch && l<=r && r>=0){
                    r--;
                }
            }
            else{
                break;
            }
        }
        if(l>r){
            return 0;
        }
        return (r-l)+1;
    }
};