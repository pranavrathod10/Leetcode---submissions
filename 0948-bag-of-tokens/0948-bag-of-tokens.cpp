class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin() , tokens.end());
        
        int l=0, r= tokens.size()-1;
        int ans = 0;
        int maxRes = 0;
        while(l <= r){
            if(power >= tokens[l]){
                power  -= tokens[l];
                l++;
                ans++;
                maxRes = max(ans, maxRes);
            }
            else if(ans >=1 ){
                power += tokens[r];
                r--;
                ans -- ;
                maxRes = max(ans,maxRes);
            }
            else{
                l++;
            }
        }

        return maxRes;
    }
};