class Solution {
public:
    bool func(int len,vector<int>& sub, int k){
        int n = len;
        if(n == 1 || k>= n/2){
            return true;
        }
        int cnt=0;
        for(int it: sub){
            if(it%2 == 1){
                cnt++;
            }
        }
        if(cnt==0 || cnt/2 <= k){
            return true;
        }

        return false;

    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int q = queries.size();
        vector<vector<int>> pre(n+1 , vector<int>(26,0));

        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i];
            pre[i+1][s[i] - 'a']++;
        }

        vector<bool> res(q);

        for (int i = 0; i < q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];

            vector<int> sub(26);
            for (int j = 0; j < 26; j++) {
                sub[j] = pre[r+1][j] - pre[l][j];
            }

            int len = r - l + 1;
            res[i] = func(len, sub, k);
        }

        return res;
    }
};