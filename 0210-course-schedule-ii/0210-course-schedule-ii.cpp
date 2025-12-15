class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto e: pre){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                ans.push_back(i);
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int node: adj[curr]){
                indegree[node]--;
                if(indegree[node] == 0){
                    q.push(node);
                    ans.push_back(node);
                }
            }
        }
        if(ans.size() != n){
            return {};
        }

        return ans;
    }
};