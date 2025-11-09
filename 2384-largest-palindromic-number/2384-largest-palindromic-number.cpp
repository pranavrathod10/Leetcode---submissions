class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> freq(10,0);
        for(auto ch: num){
            freq[ch-'0']++;
        }

        string a="" , b = "";
        int mid = -1;

        for(int d=9; d>=0;d--){
            if(freq[d]>0){
                int cnt = freq[d];
                a.append(cnt/2,d+'0');
                b.append(cnt/2,d+'0');
                if(freq[d]%2 == 1 && mid == -1){
                    mid = d;
                    // b.append(cnt)
                }


            }

            
        }
        if(a == "" || a[0]=='0'){
            return to_string(mid>0 ? mid : 0);
        }
        if(mid>=0){
            a += mid+'0';
        }
        reverse(b.begin(),b.end());
        return a + b;
        
    }
};