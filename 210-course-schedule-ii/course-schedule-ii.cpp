class Solution {
public:

    bool Util(int& numCourses, int index, unordered_map<int, vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited){

        visited[index]=1;
        pathVisited[index]=1;

        for(auto it: adj[index]){
            if(!visited[it]){
                bool hello=Util(numCourses, it, adj, visited, pathVisited);
                if(hello){
                    return true;
                }
            }
            else if(pathVisited[it] == 1){
                return true;
            }
        }
        pathVisited[index]=0;
        return false;
    }

    bool detectCycle(int& numCourses, unordered_map<int, vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited){

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(Util(numCourses, i, adj, visited, pathVisited)){
                    return true;
                }
            }
        }   
        return false;
    }

    void dfs(int index, unordered_map<int,vector<int>>& adj, vector<int>& ans, vector<int>& visited){
        // cout<<"HI"<<endl;
        for(auto it: adj[index]){
            if(!visited[it]){
                visited[it]=1;
                dfs(it, adj, ans, visited);
            }
        }
        ans.push_back(index);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        int size=prerequisites.size();

        vector<int> ans;
        vector<int> visited(numCourses,0);
        vector<int> pathVisited(numCourses,0);

        for(int i=0; i<size; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // cout<<"HI"<<endl;
        if(detectCycle(numCourses, adj, visited, pathVisited)){
            return {};
        }
        // cout<<"HI"<<endl;
        // for(auto it: visited){
        //     it=0;
        // }
        // visited[0]
        vector<int> visited1(numCourses,0);
        for(int i=0; i<numCourses; i++){
            if(!visited1[i]){
                // cout<<"hi"<<endl;
                visited1[i]=1;
                dfs(i, adj, ans, visited1);
            }
        }
        reverse(ans.begin(), ans.end());


        // vector<int> indegree(numCourses,0);
        // for(int i=0; i<size; i++){
        //     adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        //     indegree[prerequisites[i][0]]++;
        // }
        // queue<int> q;
        // for(int i=0; i<numCourses; i++){
        //     if(indegree[i] == 0){
        //         ans.push_back(i);
        //         q.push(i);
        //     }
        // }

        // while(!q.empty()){
        //     int front=q.front();
        //     q.pop();
        //     for(auto it: adj[front]){
        //         indegree[it]--;
        //         if(indegree[it] == 0){
        //             q.push(it);
        //             ans.push_back(it);
        //         }
        //     }
        // }
        // if(ans.size() != numCourses){
        //     return {};
        // }

        return ans;
    }
};






