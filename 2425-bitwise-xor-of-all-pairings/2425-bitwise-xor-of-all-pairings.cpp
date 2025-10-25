class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        int xor1 = 0, xor2=0;
        for(auto a:nums1){
            xor1 ^= a;
        }
        for(auto a:nums2){
            xor2 ^= a;
        }

        return (len2%2 * xor1) ^ (len1%2 * xor2);
       
    }
};