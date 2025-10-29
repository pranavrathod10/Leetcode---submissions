class Solution {
public:
    int minSwaps(string s) {
        int zeros=0,ones=0;
        int n=s.length();
        for(auto it:s){
            if(it == '0'){
                zeros++;
            }
            else{
                ones++;
            }
        }
        if(abs(zeros-ones)>1){
            return -1;
        }
        
        if(abs(zeros - ones)==0){
            int ans1 = 0,ans2=0;
            for(int i=0;i<n;i++){
                if(i%2 == 0){
                    if(s[i]=='1'){
                        ans1++;
                    }
                    else{
                        ans2++;
                    }
                }
                else{
                    if(s[i]=='0'){
                        ans1++;
                    }
                    else{
                        ans2++;
                    }
                }
            }
            return min(ans1/2,ans2/2);
        }
        if(zeros>ones){
            int ans = 0;
            for(int i=0;i<n;i++){
                if(i%2==0 && s[i]=='1'){
                    ans++; 
                }
                else if(i%2==1 && s[i]=='0'){
                    ans++;
                }
            }
            return ans/2;
        }
        else{
            int ans = 0;
            for(int i=0;i<n;i++){
                if(i%2==0 && s[i]=='0'){
                    ans++; 
                }
                else if(i%2==1 && s[i]=='1'){
                    ans++;
                }
            }
            return ans/2;
        }
    }
};