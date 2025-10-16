class Solution {
public:
    bool func(string txt, string pattern,int cnt){
        int u = 0, d = 0;
        int txtCnt = 0;
        bool flag = false;
        int matchedCnt = 0;
        while(u < txt.length()){
            if(txt[u]>='A' && txt[u]<='Z'){
                txtCnt++;
            }
            if(txt[u] == pattern[d] && d<pattern.length() ){
                u++;
                d++;
                matchedCnt++;
                if(matchedCnt == pattern.length()){
                    flag = true;
                }
            }
            else{
                u++;
            }
        }
        if(txtCnt != cnt){
            return false;
        }
        if(flag == true){
            return true;
        }
        return false;

    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> ans(n,false);
        int upperCaseCnt = 0;
        for(auto s: pattern){
            if(s>='A' && s<='Z'){
                upperCaseCnt++;
            }
        }
        for(int i=0;i<n;i++){
            ans[i] = func(queries[i],pattern,upperCaseCnt);
        }
        return ans;
    }
};