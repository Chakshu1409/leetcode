class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<vector<int>>> adjency;
        int size=flights.size();

        for(int i=0; i<size; i++){
            adjency[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, 0, src});  // numStops, distance, node

        vector<int> ansDist(n, INT_MAX);
        ansDist[src]=0;

        while(!pq.empty()){

            int node=pq.top()[2];
            int currDist=pq.top()[1];
            int currentSteps=pq.top()[0];

            pq.pop();
            if(currentSteps==k+1){
                continue;
            }
            for(auto it: adjency[node]){
                if(currDist + it[1] < ansDist[it[0]]){
                    ansDist[it[0]]=currDist + it[1];
                    pq.push({currentSteps+1, ansDist[it[0]], it[0]});
                }
            }

        }
        if(ansDist[dst] == INT_MAX){
            return -1;
        }
        return ansDist[dst];
    }
};