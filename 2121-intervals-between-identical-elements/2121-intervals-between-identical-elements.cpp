class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,long long > cnt,sum;
        vector<long long > res(n,0);

        for(int i=0;i<n;i++){
            if(cnt.count(arr[i])>0){
                res[i] += (i*cnt[arr[i]] - sum[arr[i]]);
            }
            cnt[arr[i]]++;
            sum[arr[i]] += i;
        }

        cnt.clear(); sum.clear();

        for(int i=n-1;i>=0;i--){
            if(cnt.count(arr[i])>0){
                res[i] += (sum[arr[i]] - i*cnt[arr[i]]);
            }
            cnt[arr[i]]++;
            sum[arr[i]] += i;
        }

        return res;
    }
};