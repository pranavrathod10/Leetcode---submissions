class Solution {
public:
    int min_ans(int a,int b,int c){
        int ans = min(a,b);
        ans = min(ans,c);
        return ans;
    }
    int func(string& word1, string& word2,int n1,int n2,vector<vector<int>>& memo){
        // int n1 = word1.size();
        // int n2 = word2.size();

        if(n1 == 0){
            memo[n1][n2] = n2;
            return n2;
        }
        if(n2 == 0){
            memo[n1][n2] = n1;
            return n1;
        }
        if(memo[n1][n2] != -1){
            return memo[n1][n2];
        }
        if(word1[n1-1] == word2[n2-1]){
            memo[n1][n2] =  func(word1,word2,n1-1,n2-1,memo);
            return memo[n1][n2];
        }
        memo[n1][n2] = min_ans(

           1+ func(word1,word2,n1,n2-1,memo),
           1+ func(word1,word2,n1-1,n2,memo),
           1+ func(word1,word2,n1-1,n2-1,memo)
        );
        return memo[n1][n2];
    }
    int minDistance(string word1, string word2) {
        // cout<<word1<<" "<<word2<<endl;
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> memo(n1+1, vector<int> (n2+1,-1));
        return func(word1,word2,n1,n2,memo);
        
    }
};