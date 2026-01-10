class Solution {
    unordered_map<long long, int> memo;
public:
    int func(int n1,int n2,string word1, string word2 ){
        if(n1 == 0 || n2 == 0){
            return 0;
        }
        long long key = (long long)n1 << 32 | n2;
        if(memo.count(key)){
            return memo[key];
        }
        
        if(word1[n1-1] == word2[n2-1]){
            return memo[key] = 1 + func(n1-1,n2-1,word1,word2);
        }

        return memo[key] = max( func(n1,n2-1,word1,word2), func(n1-1,n2,word1,word2));
    }
    int minDistance(string word1, string word2) {
        int lcs = func(word1.size(),word2.size(),word1,word2);
        return (word1.size()+word2.size()) - (2*lcs);
    }
};