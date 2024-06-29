class Solution {
public:
    void dfs(unordered_map<int, vector<int> >& adjencyList, int startInd, vector<vector<int>>& ans, vector<int>& visited, int& start){
        visited[startInd] = 1;
        for(auto it: adjencyList[startInd]){
            if(visited[it] == 0){
                ans[it].push_back(start);
                dfs(adjencyList, it, ans, visited,start);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int edgeSize=edges.size();

        vector<vector<int>> ans(n);

        unordered_map<int, vector<int> > adjencyList;

        for(int i=0; i<edgeSize; i++){
            adjencyList[edges[i][0]].push_back(edges[i][1]);
        }

        

        vector<int> visited(n,0);
        for(int i=0; i<n; i++){
            int startInd=i;
            // visited[i]=1;
            int start=i;
            dfs(adjencyList,startInd,ans,visited, start);
            for(int j=0; j<n; j++){
                visited[j] = 0;
            }
        }

        return ans;

    }
};