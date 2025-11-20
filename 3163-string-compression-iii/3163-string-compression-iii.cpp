class Solution {
public:
    string compressedString(string word) {
        int i=1;
        int n = word.length();
        int cnt=1;
        char ch = word[0];
        string res = "";
        if(n == 1){
            return (to_string(cnt)+ch);
        }
        while(i<n){
            if(word[i] == ch){
                cnt++;
            }
            else{
                res += to_string(cnt) + ch;

                cnt = 1;
                
                ch = word[i];
                
                
            }

            if(i == n-1){
                res += to_string(cnt) + ch;
            }
            else if(cnt == 9){
                res += to_string(cnt) + ch;
                cnt = 0;
                if(i+1 < n){
                    ch = word[i+1];
                }

            }
            i++;
        }

        return res;
    }
};