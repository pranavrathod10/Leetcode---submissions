class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& preReq) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto e: preReq){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;
        int ans=0;
        for(int i=0;i<n;i++){

            if (indegree[i] == 0){
                q.push(i);
                ans++;
            } 
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int node: adj[curr]){
                indegree[node]--;
                if(indegree[node] == 0){
                    q.push(node);
                    ans++;
                }
            }
        }
        if(ans == n){
            return true;
        }

        return false;
    }
};