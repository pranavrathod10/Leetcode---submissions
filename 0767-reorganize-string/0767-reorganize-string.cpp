class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        int n = s.length();
        unordered_map<char,int> mp;
        for(auto ch: s){
            mp[ch]++;
            if((2*mp[ch]-n)>1){
                return res;
            }
        }
        priority_queue<pair<int ,char>> pq;
        // set<char> sett;
        for(auto it:mp){
            pq.push({it.second,it.first});
            // sett.inset(it.second);
        }

        while(!pq.empty()){
            auto top = pq.top();
            char topChar = top.second;
            int freq = top.first;

            pq.pop();
            if(freq>1 && pq.empty()){
                return "";
            }
            if(freq == 1 && pq.empty()){
                res += topChar;
            }
            else{
                auto topSecond = pq.top();
                pq.pop();
                char topSecondChar = topSecond.second;
                int topSecondFreq = topSecond.first;

                // while(topSecondFreq>0){
                res += topChar ;
                res += topSecondChar;
                topSecondFreq--;freq--;
                // }
                if(topSecondFreq>0){
                    pq.push({topSecondFreq,topSecondChar});
                }
                if(freq>0){
                    pq.push({freq,topChar});
                }
                
            }

        }
        return res;
        

    }
};