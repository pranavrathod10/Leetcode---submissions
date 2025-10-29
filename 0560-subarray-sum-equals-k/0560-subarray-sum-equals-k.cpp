class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum=0;
        mp[0]++; // this includes subarray from i=0
        int ans = 0;
        for(auto it:nums){
            sum+=it;
            ans += mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};