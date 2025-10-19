class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> dist(n+1,0);
        set<int> sett;
        for(int i=0;i<n;i++){
            sett.insert(s[i]);
            dist[i+1] = sett.size();
        }
        vector<int> postDist(n+1,0);
        set<int> st;
        for(int i=n-1;i>=0;i--){
            st.insert(s[i]);
            postDist[i] =  st.size();
        }

        int i=0;
        int ans=0;
        while(i<n-1){
            if(dist[i+1] == postDist[i+1]){
                ans++;
                // cout<<i<<endl;
            }
            i++;
        }
        return ans;
    }
};