class Solution:
    def solve(self, l: int, r: int, s: str) -> int:
        if l == r:
            return 1
        if l > r:
            return 0

        key = (l<<32)|r
        if key in self.memo:
            return self.memo[key] 

        if s[l] == s[r]:
            self.memo[key] =  2+ self.solve(l+1,r-1,s)
        else:
            self.memo[key] = max(self.solve(l+1,r,s) , self.solve(l,r-1,s))

        return self.memo[key]

    def longestPalindromeSubseq(self, s: str) -> int:
        self.memo = {}
        l,r = 0,len(s)-1
        # n = len(s)
        return self.solve(l,r,s)
