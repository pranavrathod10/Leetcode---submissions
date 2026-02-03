class Solution:
    def isPal(self, s: str) -> bool :
        st ,e = 0, len(s)-1
        while st < e:
            if s[st] != s[e]:
                return False
            st+=1
            e-=1
        
        return True
    
    def solve(self,s: str) -> int:
        # print(s)
        if self.isPal(s):
            # print(s)
            return len(s)
        
        if s in self.memo:
            return self.memo[s]
        
        n = len(s)
        st ,e = 0, len(s)-1
        ans = 0
        while st < e:
            if s[st] != s[e]:
                str1 = s[st:e]
                str2 = s[st+1:e+1]

                ans = self.memo[s] = 2*(st) + max(self.solve(str1) , self.solve(str2))
                break

            st+=1
            e-=1

        return ans



    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        ans = 0
        self.memo = {}
        return self.solve(s)

