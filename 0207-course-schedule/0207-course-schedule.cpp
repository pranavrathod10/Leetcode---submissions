class Solution {
public:
    bool func(int n,vector<vector<int>>& adj,vector<bool>& visited,int node,int parent){
        if(visited[node] == true){
            return false;
        }

        visited[node] = true;

        for(int x: adj[node]){
            if(func(n,adj,visited,x,node) == false){
                return false;
            }
        }
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        for(auto edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int t = q.front();
            cout<<t<<endl;
            ans.push_back(t);
            q.pop();
            for(int node: adj[t]){
                indegree[node]--;
                if(indegree[node] == 0){
                    q.push(node);
                }
            }
        }

        if(ans.size() == numCourses){
            return true;
        }

        return false;
    }
};