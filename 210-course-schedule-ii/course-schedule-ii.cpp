class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++){
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
        if(ans.size() != numCourses){
            return {};
        }

        return ans;


    }
};