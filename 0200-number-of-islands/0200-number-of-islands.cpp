class Solution {
public:
    void func(vector<vector<char>>& grid,vector<vector<int>>& visited,int x,int y,int row,int col){
        if(x<0 || y<0 || x>=row || y>=col || visited[x][y] == 1 || grid[x][y] == '0'){
            return ;
        }

        visited[x][y] = 1;

        func(grid,visited,x-1,y,row,col);
        func(grid,visited,x,y+1,row,col);
        func(grid,visited,x+1,y,row,col);
        func(grid,visited,x,y-1,row,col);

        return ;
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col,0));
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && visited[i][j] == 0){
                    func(grid,visited,i,j,row,col);
                    ans++;
                }
            }
        }
        return ans;
    }
};