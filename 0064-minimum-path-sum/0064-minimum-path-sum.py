class Solution:
    def solve(self, x:int, y:int , r:int, c:int , grid:List[List[int]])->int :
        if x<0 or y<0 or x>= r or y>=c:
            return float('inf')

        if (x,y) in self.memo:
            return self.memo[(x,y)]

        if x == r-1 and y == c-1:
            return grid[x][y]

        self.memo[(x,y)] = grid[x][y] +  min( self.solve(x+1,y,r,c,grid) , self.solve(x,y+1,r,c,grid))

        return self.memo[(x,y)]

    def minPathSum(self, grid: List[List[int]]) -> int:
        self.memo = {}
        row, col = len(grid), len(grid[0])
        return self.solve(0,0,row,col,grid)