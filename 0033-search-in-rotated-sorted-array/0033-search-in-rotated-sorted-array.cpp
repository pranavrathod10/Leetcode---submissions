class Solution {
public:
    int func(vector<int>& nums){
        int n = nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else{
                r= mid;
            }
        }
        return l;
    }
    int search(vector<int>& nums, int tar) {
        int minidx = 0;
        int n = nums.size();
        int l=0,r=n-1;
        
        if(n==1 || n == 2 || n==3){
            // int ans = 0;
            for(int i=0;i<n;i++){
                if(nums[i] == tar){
                    return i;
                }
            }
            return -1;
        }

        minidx = func(nums);
        cout<<"maxidx - "<<minidx<<endl;
        l=0;r=n-1;
        if(nums[minidx] == tar){
            return minidx;
        }
        else if(minidx == 0){
            l=0;r= n-1;
        }
        else if(tar <= nums[minidx-1] && tar >= nums[l]){
            l = 0;
            r = minidx-1;
        }
        else{
            r = n-1;
            l = minidx+1;
        }
        while(l<=r && r<n){
            int mid = l + (r-l)/2;
            // cout<<l<<r<<mid<<endl;
            if(nums[mid] == tar){
                return mid;
            }
            else if(nums[mid] > tar){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;

    }
};