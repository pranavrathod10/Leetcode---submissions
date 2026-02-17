class Solution:
    def oddPal(self,idx:int, s: str, n:int) -> str:
        ans = ""
        l =r= idx

        while l>=0 and r<n:
            if s[l] != s[r]:
                break
            l-=1
            r+=1
        
        return s[l+1:r]

    def evenPal(self, l:int, r:int, s: str, n: int):
        while l>=0 and r<n:
            if s[l] != s[r]:
                break
            l-=1
            r+=1
        
        return s[l+1:r]


    def longestPalindrome(self, s: str) -> str:
        ans = ""
        maxLen = 0
        n = len(s)
        for i in range(n):
            odd = even = ""

            odd = self.oddPal(i,s,n)
            if i<n-1:
                even = self.evenPal(i,i+1,s,n)

            if len(odd) > maxLen:
                ans = odd
                maxLen = len(odd)
            
            if len(even) > maxLen:
                ans = even
                maxLen = len(even)

        return ans