class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        priority_queue<
            pair<string,string>
        > pq;
        vector<string> ans;

        for(int i=0;i<logs.size();i++){
            int idx = 0;
            while(logs[i][idx] != ' '){
                idx++;
            }

            if(logs[i][idx+1] >= 'a' && logs[i][idx+1] <= 'z'){
                pq.push({logs[i].substr(idx+1,100),logs[i]});
            }
            else{
                ans.push_back(logs[i]);
            }
        }

        while(!pq.empty()){
            ans.insert(ans.begin(),pq.top().second);
            pq.pop();
        }
        return ans;
    }
};