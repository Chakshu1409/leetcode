class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=0;
        unordered_map<char,int> map;
        for(int i=0; i<tasks.size(); i++){
            map[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto it: map){
            pq.push(it.second);
        }
        queue<pair<int,int>> q; 
        while(!(pq.empty()&&q.empty())){
            time++;
            if(!pq.empty()){
                int top=pq.top(); pq.pop();
                if(top>1){
                    q.push({time+n, top-1});
                }
            }
            if(!q.empty()){
                int timeReq=q.front().first;
                int currFreq=q.front().second;
                if(time==timeReq){
                    q.pop();
                    pq.push(currFreq);
                }
            }
        }
        return time;
    }
};