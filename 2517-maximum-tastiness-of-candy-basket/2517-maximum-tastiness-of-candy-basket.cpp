class Solution {
public:
    int maximumTastiness(vector<int>& prices, int k) {
        int n = prices.size();
        sort(prices.begin(), prices.end());

        int l = 0, r = prices[n-1]- prices[0];
        int maxDiff = r-l;
        
        while(l<r){
            int mid = l + (r-l + 1)/2;
            int cnt = 1;
            int start = 0, next = 1;
            while(next<n && cnt<k){
                int currDiff = prices[next] - prices[start];
                if(currDiff >= mid){
                    cnt++;
                    start = next;
                    
                }
                next++;
            }
            if(cnt<k){
                r = mid-1;
            }
            else{
                l = mid;
            }
        }
        return l;
    }
};