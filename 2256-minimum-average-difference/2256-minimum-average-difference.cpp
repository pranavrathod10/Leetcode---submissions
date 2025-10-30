class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n= nums.size();
        vector<long long> presum(n,0);
        presum[0] = nums[0];
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1]+nums[i];
        }
        int res = INT_MAX;
        int ans_idx = 0;
        for(int i=0;i<n;i++){
            int avg1,avg2;
            if(i==n-1){
                avg1 = presum[i]/(i+1);
                avg2 = 0;
            }
            else{
                avg1 = presum[i]/(i+1);
                avg2 = (presum[n-1]- presum[i])/(n-i-1);
            }
            
            int diff = abs(avg1 - avg2);
            if(res > diff){
                res = diff;
                ans_idx = i;
            }
        }
        return ans_idx;
    }
};