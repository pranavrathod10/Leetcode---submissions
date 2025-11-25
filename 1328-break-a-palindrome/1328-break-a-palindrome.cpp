class Solution {
public:
    string breakPalindrome(string pal) {
        int n = pal.length();
        if(n == 1){
            return "";
        }
        string res = "";
        bool flag = true;
        for(int i=0;i<n;i++){
            if(n%2 == 1 && i == n/2){
                continue;
            }
            if(pal[i] > 'a'){
                
                flag = false;
                if(i == 0){
                    return 'a' + pal.substr(1,n-1);
                }
                else{
                    return pal.substr(0,i) + 'a' + pal.substr(i+1,n);
                }
            }
        }
        if(flag == true ){
            return pal.substr(0,n-1) + 'b';
        }
        return res;
    }
};