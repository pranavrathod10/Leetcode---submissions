class Solution {
public:
    string func(string ans){
        string res = "";
        int n = ans.length();
        if(ans == "1"){
            return "11";
        }
        for(int i=0;i<ans.length();i++){
            int cnt=1;
            string temp = ans.substr(i,1); 
            if(i==n-1 && ans[i]!=ans[i-1]){
                res += "1"+temp;
                break;
            }
            
            while(i<n-1 && ans[i]==ans[i+1]){
                cnt++;
                i++;
            }
            res += to_string(cnt) + temp ;

        }
        return res;
    }
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string ans = "1";
        for(int i=2;i<=n;i++){
            ans = func(ans);
        }
        return ans;
    }
};