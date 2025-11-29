class Solution {
public:
    string breakPalindrome(string pal) {
        string res = "";
        int len = pal.length();
        bool flag = true;
        if(len == 1){
            return res;
        }

        for(int i=0;i<len;i++){
            if(pal[i] != 'a'){
                if(len%2 == 1 && i == len/2){
                    continue;
                }
                flag = false;
                res = pal.substr(0,i) + 'a';
                if(i+1 < len){
                    res += pal.substr(i+1,len);
                }
                break;
                
            }
        }

        if(flag == true){
            return pal.substr(0,len-1)+'b';
        }

        return res;
    }
};