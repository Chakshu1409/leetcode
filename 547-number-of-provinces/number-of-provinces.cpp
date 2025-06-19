class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj, vector<int>& visited, int current){

        visited[current]=1;

        for(auto it: adj[current]){
            if(!visited[it]){
                dfs(adj,visited,it);
            }
        } 

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> adj;

        int size=isConnected.size();
        
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(size,0);
        int count=0;
        for(int i=0; i<size; i++){
            if(!visited[i]){
                count++;
                dfs(adj,visited,i);
            }
        }
        return count;
    }
};