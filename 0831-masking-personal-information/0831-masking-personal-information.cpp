class Solution {
public:
    string email_func(string s){
        for(char &c : s) c = tolower(c);
        char first = s[0];
        char last ;
        int lastIdx = -1;;
        for(int i=0;i<s.length();i++){
            if(s[i] == '@'){
                last = s[i-1];
                lastIdx = i-1;
                break;
            }
        }
        string res = "";
        res += first;
        res += "*****";
        if(lastIdx > 0){
            res += last ;
        }
        else{
            res+= "";
        }

        res += s.substr(lastIdx+1,s.length());
        
        return res;
    }
    string num_func(string s){
        int k=4, r = s.length()-1;
        string lastPart = "";
        while(r>=0 && k>0){
            if(s[r]>='0' && s[r]<='9'){
                lastPart = s[r] + lastPart;
                k--;
            }
            r--;
        }
        int cnt = 0;
        for(char c: s){
            if(c>='0' && c<='9'){
                cnt++;
            }
        }
        int cntryLen = cnt - 10;
        string res = "";
        res += "***-***-" + lastPart;
        // cout<<res<<endl;
        if(cntryLen>0){
            res = "-" + res;
            string first = "+";
            for(int i=0;i<cntryLen;i++){
                first += "*";
            }
            res = first + res;
        }
        
        return res;

    }
    string maskPII(string s) {
        int n = s.length();
        if(tolower(s[0])>='a' && tolower(s[0])<='z'){
            return email_func(s);
        }
        else{
            return num_func(s);
        }
    }
};