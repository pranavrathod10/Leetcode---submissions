class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int l=0,r=n-1;
        
        int ans = 0;
        // vector<bool> visited(n,false);
        while(l<=r){
            int curr = people[l];
            if(l == r){
                ans++;
                break;
            }
            curr+= people[r];
            if(curr <= limit){
                r--;
                l++;
                
            }
            else{
                r--;
            }
            ans++;
        }

        return ans;
    }
};