class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int time = 0;
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<tasks.size();i++){
            pq.push({tasks[i],i});
        }
        sort(processorTime.begin(),processorTime.end());
        for(int t: processorTime){
            int maxTime = t;
            for(int i=0;i<4;i++){
                maxTime = max(maxTime,t+pq.top().first);
                pq.pop();
            }
            time = max(time,maxTime);
        }

        return time;
    }
};