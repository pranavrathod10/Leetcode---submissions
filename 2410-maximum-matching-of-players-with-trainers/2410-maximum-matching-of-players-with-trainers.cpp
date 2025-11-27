class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end(),greater<int>());
        sort(trainers.begin(),trainers.end(),greater<int>());

        int t=0, p=0;
        int ans = 0;
        while(t<trainers.size() && p<players.size()){
            if(trainers[t]>=players[p]){
                t++;
                p++;
                ans++;
            }
            else{
                p++;
            }
        }

        return ans;
    }
};