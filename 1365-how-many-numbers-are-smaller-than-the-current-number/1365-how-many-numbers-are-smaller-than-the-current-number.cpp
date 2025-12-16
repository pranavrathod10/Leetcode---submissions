class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // vector<int> ans(n,0);
        int n=nums.size();
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            mp[temp[i]] = i;
        }

        for(int i=0;i<n;i++){
            nums[i] = mp[nums[i]];
        }
        
        return nums;
    }
};