class Solution {
public:
    long long coloredCells(int n) {
        
        if(n == 1){
            return 1;
        }
        long long ans = 1;
        int i=2;
        while(i<=n){
            ans += 4*(i-1);
            i++;
        }
        return ans;

    }
};