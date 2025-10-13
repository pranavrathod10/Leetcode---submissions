class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int> mp;
        for(auto i: banned){
            mp[i]++;
        }
        int sum = 0;
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(mp.count(i) == 0 ){
                // cout<<i<<endl;
                sum+= i;
                if(sum <= maxSum){
                    ans++;
                }
                else{
                    break;
                }
                
            }
        }
        return ans;
    }
};