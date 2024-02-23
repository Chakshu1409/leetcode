class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            int stop=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();

            if(stop>k) continue;
            for(int i=0;i<adj[node].size();i++){
                int adjNode=adj[node][i].first;
                int costWt=adj[node][i].second;
                if(cost+costWt < dist[adjNode] && stop<=k){
                    dist[adjNode]=cost+costWt;
                    q.push({stop+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};