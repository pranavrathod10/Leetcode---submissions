class Solution:
    # def solve(self,x: int, y: int, r: int, c: int, grid: List[List[int]]) -> int:
    #     if x<0 or y<0 or x>= r or y>= c:
    #         return float('inf')




    def calculateMinimumHP(self, grid: List[List[int]]) -> int:
        self.memo = {}
        row, col = len(grid), len(grid[0])
        memo = [[float('inf') for _ in range(col+1)] for _ in range(row+1)]
        memo[row-1][col] = 1
        memo[row][col-1] = 1

        # return self.solve(row-1,col-1,row,col,grid)+1
        for i in range(row-1,-1,-1):
            for j in range(col-1,-1,-1):
                val = min(memo[i][j+1] , memo[i+1][j]) - grid[i][j]
                memo[i][j] = max(1, val)


        return memo[0][0]