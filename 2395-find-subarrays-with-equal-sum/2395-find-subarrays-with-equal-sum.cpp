class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            int temp = nums[i] + nums[i+1];
            if(mp[temp]>0){
                return true;
            }
            mp[temp] = i+1;
        }
        return false;
    }
};