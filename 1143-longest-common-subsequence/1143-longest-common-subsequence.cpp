class Solution {
    vector<vector<int>> memo;
public:
    int func(string text1, string text2,int n1,int n2){
        if(n1 ==0 || n2 ==0){
            return 0;
        }
        // long long key = (long long)n1 << 32 | n2;
        if(memo[n1][n2] != -1){
            return memo[n1][n2];
        }
        if(text1[n1-1] == text2[n2-1]){
            memo[n1][n2] = 1 + func(text1,text2,n1-1,n2-1);
            return memo[n1][n2];
        }

        return memo[n1][n2] = max( func(text1,text2,n1,n2-1), func(text1,text2,n1-1,n2) );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        memo.resize(n1+1, vector<int>(n2+1, -1));
        // for(int i=)
        return func(text1,text2,n1,n2);
    }
};