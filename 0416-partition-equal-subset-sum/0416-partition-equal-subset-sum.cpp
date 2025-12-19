class Solution {
public:
    bool func(int W,vector<vector<int>>& memo,vector<int>& nums,int n ){
        // cout<<"w - "<<W<<" "<<"n - "<<n<<endl;
        if(n == 0 && W == 0){
            memo[n][W] == 1;
            return true;
        }
        else if(n==0){
            memo[n][W] == 0;
            return false;
        }

        if(memo[n][W] != -1){
            if(memo[n][W] == 0){
                return false;
            }
            return true;
        }
        bool in = false, out = false;
        if(W-nums[n-1]>=0){
            in = in || func(W-nums[n-1],memo,nums,n-1);
        }
        out = out || func(W,memo,nums,n-1);

        if( (in || out) == true){
            memo[n][W] = 1;
            return true;
        }
        else{
            memo[n][W] = 0;
            return false;
        }
        // return memo[n][W]== 0 ? false: true;

    }
    bool canPartition(vector<int>& nums) {
        int W = 0;
        for(int x: nums){
            W += x;
        }
        if(W%2 == 1){
            return false;
        }
        vector<vector<int>> memo(nums.size()+1, vector<int>(W+1, -1));
        return func(W/2,memo,nums,nums.size());
    }
};