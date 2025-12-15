class UnionFind {
    private:
        vector<int> parent;
    public:
        UnionFind(int size){
            parent.resize(size+1);
            for(int i=0;i<size+1;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(parent[x] == x){
                return x;
            }
            return find(parent[x]);
        }

        void Union(int a, int b){
            int pa = find(a);
            int pb = find(b);

            parent[pb] = pa; 

            return ;
        }
};

class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        UnionFind* ui = new UnionFind(edges.size());
        for(auto e: edges){
            if(ui->find(e[0]) == ui->find(e[1])){
                ans = e;
            }
            ui->Union(e[0],e[1]);
        }
        return ans;
    }
};

