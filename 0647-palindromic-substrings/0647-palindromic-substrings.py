class Solution:
    def isPal(self, s: str)-> bool:
        st, e = 0, len(s)-1
        while st<e:
            if s[st] != s[e]:
                return False
            st+=1
            e-=1
        
        return True

    def solveOdd(self, s: str, idx: int) -> int:
        n = len(s)
        l=r=idx
        ans = 0
        while l>=0 and r<n:
            if s[l] == s[r]:
                ans+=1
            else:
                break
            l-=1
            r+=1
        return ans
        
    def solveEven(self,s:str,idx: int) -> int:
        if idx == len(s)-1:
            return 0
        
        l,r = idx, idx+1
        n = len(s)
        ans = 0
        while l>=0 and r<n:
            if s[l] == s[r]:
                ans+=1
            else:
                break
            l-=1
            r+=1
        
        return ans



    def countSubstrings(self, s: str) -> int:
        n = len(s)
        # return self.solve(s,0,n)
        ans = 0
        for i in range(n):
            ans += self.solveOdd(s,i) + self.solveEven(s,i)

        return ans
