class Solution {
public:
    bool isCapital(char ch){
        if(ch>='A' && ch<='Z'){
            return true;
        }
        return false;
    }
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n == 1){
            return true;
        }
        bool isvalid = true;
        for(int i=0;i<n;i++){
            if(!isCapital(word[i])){
                isvalid = false;
            }
        }
        if(isvalid){
            return true;
        }
        bool flag2 = true;
        for(int i=0;i<n;i++){
            if(isCapital(word[i])){
                flag2 = false;
                break;
            }
        }
        if(flag2 == true){
            return true;
        }

        bool flag3 = true;
        if(!isCapital(word[0])){
            flag3 = false; 
        }
        for(int i=1;i<n;i++){
            if(isCapital(word[i])){
                flag3 = false;
            }
        }
        if(flag3){
            return true;
        }

        return false;
    }
};