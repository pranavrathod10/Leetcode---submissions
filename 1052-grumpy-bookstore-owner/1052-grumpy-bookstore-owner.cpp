class Solution {
public:
    int maxSatisfied(vector<int>& cus, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int l=0,r=0;
        int n = cus.size();
        int act = 0;
        for(int i=0;i<n;i++){
            act += cus[i]*grumpy[i];
        }
        for(int i=0;i<=(n-minutes);i++){
            int temp = act;
            for(int j=i;j<i+minutes;j++){
                if(grumpy[j] == 0){
                    temp+= cus[j];
                }
            }
            ans = max(ans, temp);
        }

        return ans;
    }
};