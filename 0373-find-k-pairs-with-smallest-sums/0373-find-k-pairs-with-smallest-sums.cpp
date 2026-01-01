class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<vector<int>> pq;
        //store the k pairs first and add if new pair is < top pair 
        for(int i=0;i<nums1.size();i++){
            // if(k==0 && nums1[i] > (pq.top()[0] + pq.top()[1]) ){
            //     break;
            // }
            for(int j=0;j<nums2.size();j++){
                int sum = nums1[i]+nums2[j];
                if(k>0){
                    pq.push({sum,nums1[i],nums2[j]});
                    k--;
                }
                else if(pq.top()[0] > sum){
                    pq.pop();
                    pq.push({sum,nums1[i],nums2[j]});
                }
                else{
                    break;
                }
            }
        }
        //we got the pair , store in array and return 
        // cout<<pq.size()<<endl;
        while(!pq.empty()){
            ans.push_back({pq.top()[1],pq.top()[2]});
            pq.pop();
        }
        return ans;
    }
};