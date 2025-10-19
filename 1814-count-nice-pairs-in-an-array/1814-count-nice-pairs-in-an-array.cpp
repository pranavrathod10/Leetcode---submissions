class Solution {
public:
    int func(int a){
        if(a == 0){
            return 0;
        }
        int num = 0;
        while(a){
            num = num*10 + a%10;
            a = a/10;

        }
        return num;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> revArray(n,0);
        unordered_map<int,long long> mp;
        for(int i=0;i<n;i++){
            revArray[i] = func(nums[i]);
            mp[revArray[i] - nums[i]]++;
        }
        
        long long ans=0;
        long long mod = 1e9 + 7;
        for(auto &[key,val]: mp){
            long long temp = val*(val-1)/2;
            ans = ans%mod + (temp)%mod;
            ans = ans%mod;
        }
        return ans%mod;
    }
};