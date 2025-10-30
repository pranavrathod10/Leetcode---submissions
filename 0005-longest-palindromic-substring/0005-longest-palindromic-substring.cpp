class Solution {
public:
    string func(string s,int l,int r){
        int n = s.length();
        if(r-l == 1){
            if(s[l]!=s[r]){
                return "";
            }
        }
        while(r<n && l>=0 && s[l]==s[r]){
            l--;
            r++;
        }
        // cout<<l+1<<"--"<<r-1<<endl;
        if(l+1 == r-1){
            return s.substr(l+1,1);
        }
        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 1){
            return s;
        }
        string res = "";
        int len = 0;
        for(int i=0;i<n;i++){
            // cout<<"i -- "<<i<<endl;
            string odd = func(s,i,i);
            // cout<<"odd = "<<odd<<endl;
            if(len < odd.length()){
                len = odd.length();
                res = odd;
            }
            string even ;
            if(i<n-1){
                even = func(s,i,i+1);
                if(len < even.length()){
                    len = even.length();
                    res = even;
                }
            }
            // cout<<"even = "<<even<<endl;
            
        }
        return res;
    }
};