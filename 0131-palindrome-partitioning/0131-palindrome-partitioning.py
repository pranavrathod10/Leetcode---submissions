class Solution:
    def isPalindrome(self, strr: str)->bool:
        s,e = 0,len(strr)-1
        while s < e:
            if strr[s] != strr[e]:
                return False
            s+=1
            e-=1
        
        return True

    def solve(self, s: str, idx: int,n: int, path: List[str]) :
        if idx == n:
            self.ans.append(path.copy())
            return

        for i in range(idx,n):
            
            if self.isPalindrome(s[idx:i+1]):
                # print(s[idx:i+1])
                path.append(s[idx:i+1])
                self.solve(s,i+1,n,path)
                path.pop()

        return 

    def partition(self, s: str) -> List[List[str]]:
        self.ans = []
        n = len(s)
        path = []
        self.solve(s,0,n,path)

        return self.ans