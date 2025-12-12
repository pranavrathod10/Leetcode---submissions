class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int maxVal = INT_MIN;
        int n = candies.size();
        for(int c: candies){
            maxVal = max(maxVal, c);
        }

        vector<bool> res(n,false);
        for(int i=0;i<n;i++){
            if((candies[i]+extra)>=maxVal){
                res[i] = true;
            }
        }
        return res;
    }
};