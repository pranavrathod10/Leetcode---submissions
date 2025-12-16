class Solution {
public:
    int func(int n, vector<vector<int>>& adj, int src){
        queue<int> q;
        vector<int> visited(n,false);
        vector<int> degree(n,0);
        q.push(src);
        int ans = 0;
        // cout<<"hi - "<<src<<endl;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            // bool flag = false;
            for(int node: adj[curr]){
                if(visited[node] == false){
                    q.push(node);
                    degree[node] = degree[curr] + 1;
                    ans = max(ans, degree[node]);
                }
            }
            // if(flag == true){
            //     cout<<curr<<endl;
            //     ans++;
            // }
        }
        return ans;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans  ;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        queue<int> q;
        vector<bool> v(n,true);
        // int cnt = 0;
        for(int i=0;i<n;i++){
            if(indegree[i] == 1){
                q.push(i);
                indegree[i]--;
                // cnt++;
                // v[i] = false;
            }
        }
        
        while(!q.empty()){
            int s = q.size();
            ans.clear();
            for(int i=0;i<s;i++){
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for(auto child: adj[curr]){
                    indegree[child]--;
                    if(indegree[child] == 1){
                        q.push(child);
                    }
                }
            }
        }
        if(n==1){
            ans.push_back(0);
        }

        return ans;
    }
};