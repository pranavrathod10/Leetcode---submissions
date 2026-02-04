class Solution:
    def isPal(self, s: str) -> bool:
        if s == s[::-1]:
            return True
        return False

    def solve(self,s: str, idx: int, n: int) -> int :
        if idx in self.memo:
            return self.memo[idx]

        if idx == n:
            return -1

        ans = float('inf')
        for i in range(idx,n):
            if self.isPal(s[idx:i+1]):
                ans = min(ans, 1+ self.solve(s,i+1, n) )

        self.memo[idx] = ans

        return ans

    def minCut(self, s: str) -> int:
        n = len(s)
        # self.ans = n
        cnt = 0
        
        self.memo ={}
        return self.solve(s,0,n)