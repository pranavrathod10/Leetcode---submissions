class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]] = i+1;
        }
        for(int i=0;i<n;i++){
            int temp = target - nums[i];
            if(mp[temp]>0 && mp[temp]-1 != i){
                return {i,mp[temp]-1};
            }
        }
        return {0,1};
    }
};