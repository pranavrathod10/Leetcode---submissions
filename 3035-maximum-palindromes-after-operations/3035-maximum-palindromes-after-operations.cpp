class Solution {
    
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        unordered_map<char,int> mp;
        priority_queue<int, vector<int> ,greater<int>> pq;
        int pairCnt = 0;
        int singleCnt = 0;
        for(auto word: words){
            for(char ch: word){
                mp[ch]++;
            }
            pq.push(word.length());
        }
        for(auto &[k,val]: mp){
            if(val%2 == 0){
                pairCnt += val/2;
            }
            else{
                pairCnt += val/2;
                singleCnt++;
            }
        }

        int ans = 0;
        while(!pq.empty()){
            int len = pq.top();
            // cout<<len<<endl;
            pq.pop();
            if(len%2 == 0){
                if(pairCnt*2 >= len){
                    ans++;
                    // cout<<"hi 1"<<endl;
                    pairCnt -= len/2;
                }
            }
            else{
                if(singleCnt>0 ){
                    len--;
                    
                    if(pairCnt*2 >= len){
                        ans++;
                        // cout<<"hi 2"<<endl;
                        singleCnt--;
                        pairCnt -= len/2;
                    }
                }
                else if(pairCnt*2 >= len){
                    ans++;
                    // cout<<"hi 3"<<endl;
                    pairCnt -= (len + 1)/2;
                    singleCnt++;
                }
                
            }
        }

        return ans;
    }
};