class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        queue<string> q;
        set<string> st;
        q.push(beginWord);
        st.insert(beginWord);

        unordered_map<string,bool> mp;
        for(string w: wordList){
            mp[w] = true;

        }
        if(mp[endWord] == false){
            return 0;
        }
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        int ans = 1;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                string curr = q.front();
                if(curr == endWord){
                    return ans;
                }
                q.pop();
                for(int idx=0;idx<n;idx++){
                    for(int ch=0;ch<26;ch++){
                        string changed = curr.substr(0,idx) + alpha[ch] + curr.substr(idx+1,n);
                        if(mp[changed] == true && st.count(changed)==0){
                            q.push(changed);
                            st.insert(changed);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};