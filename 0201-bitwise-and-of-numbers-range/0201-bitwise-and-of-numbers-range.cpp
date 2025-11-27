class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 1;
        int n = right;
        while(n>left){
            // cout<<ans<<" "<<n<<endl;
            n = n&(n-1);
            // n--;
        }
        return n;
    }
};