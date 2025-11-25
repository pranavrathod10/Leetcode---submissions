class Solution {
public:
    int func(int node, vector<vector<int>>& uadj,vector<vector<int>>& dadj, vector<bool>& visited){
        visited[node] = true;
        int res = 0;
        for(auto adjNode: uadj[node]){
            if(visited[adjNode] == true){
                continue;
            }
            bool flag = false;
            for(auto x: dadj[adjNode]){
                if(x == node){
                    flag = true ;
                    // cout<<" call - ("<<adjNode<<")"<<endl;
                    res += func(adjNode,uadj,dadj,visited);
                    break;
                }
            }

            if(flag == false){
                // cout<<" call - ("<<adjNode<<")"<<endl;
                res += 1 + func(adjNode,uadj,dadj,visited);
            }

        }

        return res;
    }
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<bool> visited(n,false);
        vector<vector<int>> uadj(n),dadj(n);
        for(auto con: conn){
            vector<int> temp;
            dadj[con[0]].push_back(con[1]);
            uadj[con[0]].push_back(con[1]);
            uadj[con[1]].push_back(con[0]);
        }

        return func(0,uadj,dadj,visited);
    }
};