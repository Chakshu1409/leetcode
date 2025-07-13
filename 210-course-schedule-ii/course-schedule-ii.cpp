class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        int size=prerequisites.size();

        vector<int> ans;
        vector<int> indegree(numCourses,0);
        for(int i=0; i<size; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                ans.push_back(i);
                q.push(i);
            }
        }

        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(auto it: adj[front]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        if(ans.size() != numCourses){
            return {};
            
        }
        return ans;
    }
};






