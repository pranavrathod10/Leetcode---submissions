class Solution:
    # def solve(col:int)
    def isSafe(self,row: int , col: int, board:List[List[str]],n:int):
        r,c = row, col
        while c>=0:
            if board[r][c] == 'Q':
                return False
            c-=1
        r,c = row, col    
        while r>=0 and c>=0:
            if board[r][c] == 'Q':
                return False
            r-=1
            c-=1

        r,c = row, col    
        while r<n and c>=0:
            if board[r][c] == 'Q':
                return False
            r+=1
            c-=1

        return True
        
    def solve(self,col:int, ans: List[List[str]], board:List[List[str]], n:int):
        if col == n:
            ans.append(["".join(row) for row in board])
            return 

        for row in range(0,n):
            if self.isSafe(row,col,board,n):
                board[row][col] = 'Q'
                self.solve(col+1,ans,board,n)
                board[row][col] = '.'
        
        return 
        
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [['.' for _ in range(n)] for _ in range(n)]
        ans = []

        self.solve(0,ans,board,n)
        return ans

        