class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rows = nums.size();

        vector<int> lastidx(rows,-1);

        vector<int> ans;
        lastidx[0] = 0;
        ans.push_back(nums[0][0]);

        queue<pair<int,int>> ptr;
        ptr.push({0,0});

        while(!ptr.empty()){
            int pairCnt = ptr.size();
            // cout<<"pairCnt -- "<<pairCnt<<endl;
            // for(int i=0;i<pairCnt;i++){
            int currRow = ptr.front().first;
            int lastColi =  ptr.front().second;
            ptr.pop(); 
            
            // cout<<"currRow , lastColi -- "<<currRow<<","<<lastColi<<" ";
            if(lastColi == 0 && currRow +1 < rows){
                ans.push_back( nums[currRow +1][0]);
                ptr.push({currRow +1,0});
                // rowCnt
            }
            if(lastColi + 1 < nums[currRow].size()){
                ans.push_back( nums[currRow][lastColi + 1] );
                ptr.push({currRow,lastColi + 1});
            }
                
                // if(currRow == 0 && lastColi + 1 == nums[0].size()-1){
                //     return ans;
                // }
            // }
            // cout<<endl;
        }

        return ans;
        
    }
};