class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int numNodes=graph.size();
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<numNodes; i++){
            for(auto ij: graph[i]){
                adj[ij].push_back(i);
            }
        }

        vector<int> indegree(numNodes, 0);

        for(auto it: adj){
            for(auto ij: it.second){
                indegree[ij]++;
            }
        }

        queue<int> q;

        for(int i=0; i<numNodes; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int front = q.front();
            ans.push_back(front);
            q.pop();

            for(auto it: adj[front]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

/*

0->3
1->0
2->0,1
3->1
4->
5->2,4
6->

*/