// class Solution {
// public:
//     void func(vector<vector<char>> grid,vector<vector<bool>>& visited,int x,int y){
//         if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y] == '0' || visited[x][y] == true){
//             return ;
//         }

//         visited[x][y] = true;

//         func(grid,visited,x-1,y);
//         func(grid,visited,x,y+1);
//         func(grid,visited,x+1,y);
//         func(grid,visited,x,y-1);

//         return ;
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         int row = grid.size();
//         int col = grid[0].size();
//         vector<vector<bool>> visited(row, vector<bool>(col,false));
//         int ans = 0;
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(grid[i][j]=='1' && visited[i][j] == false){
//                     func(grid,visited,i,j);
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:

    void dfs(vector<vector<char>>& grid , vector<vector<int>>& vis , int i , int j , int n , int m){
        if(i < 0 || i > n-1 || j < 0 || j > m-1 || vis[i][j] == 1 || grid[i][j] == '0') return;
        vis[i][j] = 1;
        dfs(grid , vis , i+1 , j , n , m);
        dfs(grid , vis , i , j+1 , n , m);
        dfs(grid , vis , i , j-1 , n , m);
        dfs(grid , vis , i-1 , j , n , m);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(grid , vis , i , j , n , m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};