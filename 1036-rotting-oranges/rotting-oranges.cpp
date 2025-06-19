class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n,0));

        queue<vector<int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }
        int ans=0;
        // cout<<q.size()<<endl;
        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int k=q.front()[2];
            q.pop();

            ans=max(ans,k);

            if(i>0 && grid[i-1][j] == 1 && visited[i-1][j] == 0){
                q.push({i-1,j,k+1});
                visited[i-1][j]=1;
            }
            if(i<m-1 && grid[i+1][j] == 1 && visited[i+1][j] == 0){
                q.push({i+1,j,k+1});
                visited[i+1][j]=1;
            }
            if(j>0 && grid[i][j-1] == 1 && visited[i][j-1] == 0){
                q.push({i,j-1,k+1});
                visited[i][j-1]=1;
            }
            if(j<n-1 && grid[i][j+1] == 1 && visited[i][j+1] == 0){
                q.push({i,j+1,k+1});
                visited[i][j+1]=1;
            }
        }

        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<visited[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<ans<<endl;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};