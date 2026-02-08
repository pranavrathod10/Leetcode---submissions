class Solution:
    def dfs(self, root: int, parent: int):

        for node in self.adj[root]:
            if node != parent:
                # sumArr[root] += dfs(node,adj,root) + self.nodeCnt[node] 
                self.dfs(node,root)
                self.nodeCnt[root] += self.nodeCnt[node]
                self.sumArr[root] += self.sumArr[node] + self.nodeCnt[node]

        self.nodeCnt[root] += 1
        return self.sumArr[root]

    def dfs2(self, root: int, n: int, parent: int):
        for node in self.adj[root]:
            if node != parent:
                self.sumArr[node] = self.sumArr[root] - self.nodeCnt[node] + n - self.nodeCnt[node]
                self.dfs2(node,n,root)

    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        self.adj = [[] for _ in range(n)]
        for [u,v] in edges:
            self.adj[u].append(v)
            self.adj[v].append(u)

        self.nodeCnt = [0]*n
        self.sumArr = [0]*n

        self.dfs(0,-1)
        self.dfs2(0,n,-1)

        return self.sumArr

