class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<vector<int>>> adj;
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0,0,src});

        vector<int> costing(n,1e9);
        costing[src]=0;

        int ans=INT_MAX;
        while(!pq.empty()){

            int numSteps = pq.top()[0];
            int cost = pq.top()[1];
            int node = pq.top()[2];

            pq.pop();

            if(node == dst){
                ans=min(ans, cost);
            }

            if(numSteps == k+1){
                continue;
            }

            for(auto it: adj[node]){
                if(costing[it[0]] > cost+it[1]){
                    costing[it[0]]= cost+it[1];
                    pq.push({numSteps+1, costing[it[0]], it[0]});
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};