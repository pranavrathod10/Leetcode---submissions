class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size();int col = grid[0].size();
        vector<pair<int,int>> rowCount,colCount;
        for(int i=0;i<row;i++){
            int cnt0 = 0,cnt1=0;
            for(int j=0;j<col;j++){
                if(grid[i][j]==0 ){
                    cnt0++;
                }
                else if(grid[i][j]==1){
                    cnt1++;
                }
                
            }
            rowCount.push_back({cnt0,cnt1});

        }
        for(int i=0;i<col;i++){
            int cnt0 = 0,cnt1=0;
            for(int j=0;j<row;j++){
                if(grid[j][i]==0 ){
                    cnt0++;
                }
                else if(grid[j][i]==1){
                    cnt1++;
                }
                
            }
            colCount.push_back({cnt0,cnt1});

        }

        vector<vector<int>> res(row, vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                res[i][j] = rowCount[i].second - rowCount[i].first + 
                    colCount[j].second - colCount[j].first;
            }
        }
        return res;
    }
};