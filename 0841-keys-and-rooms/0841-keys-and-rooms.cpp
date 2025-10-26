class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int idx,int n,unordered_map<int,bool>& mp){
        if(mp[idx]){
            return ;
        }
        mp[idx] = true;

        for(auto roomNo: rooms[idx]){
            dfs(rooms,roomNo,n,mp);
        }

        return ;
        
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int,bool> mp;
        dfs(rooms,0,n,mp);
        for(int i =0;i<n;i++){
            if(mp[i] == false){
                return false;
            }
        }
        return true;
    }
};