class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(int t: target){
            pq.push(t);
            sum+=t;
        }

        while(!pq.empty()){
            
            long long maxe = pq.top();
            if(maxe == 1){
                return true;
            }
            pq.pop();
            if(pq.size() == 1 && pq.top() == 1){
                return true;
            }
            else if(pq.size() == 1 && maxe%pq.top() == 0){
                return false;
            }

            long long remaining_sum = sum - maxe;
            if (remaining_sum == 0 || maxe < remaining_sum)
                return false;
            long long newe = maxe%remaining_sum;
            if(remaining_sum > maxe || newe == 0){
                return false;
            }
            pq.push(newe);
            sum = sum - maxe + newe;
        }

        return true;
    }
};