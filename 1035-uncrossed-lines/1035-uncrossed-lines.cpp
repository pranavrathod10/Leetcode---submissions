class Solution {
    unordered_map<long long, int> memo;
public:
    int func(vector<int>& nums1, vector<int>& nums2,int n1, int n2){
        if( n1 == 0 || n2 == 0){
            return 0;
        }
        long long key = (long long )n1 << 32 | n2;
        if(memo.count(key)){
            return memo[key];
        }
        
        if( nums1[n1-1] == nums2[n2-1]){
            return memo[key] = 1 + func(nums1,nums2,n1-1,n2-1);
        }

        return memo[key] = max( func(nums1,nums2,n1,n2-1) , func(nums1,nums2,n1-1,n2));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        return func(nums1,nums2,n1,n2);
    }
};