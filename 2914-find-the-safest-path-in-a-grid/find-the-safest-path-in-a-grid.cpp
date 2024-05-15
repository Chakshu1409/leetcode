// class Solution {
// public:
//     void dfs(int& n, vector<vector<int>>& grid, vector<vector<int>>& gridClosest1, int si, int sj, int currentmin, vector<vector<int>> visited, int& ans){
//         if(si==n-1 && sj==n-1){
            
//             currentmin=min(currentmin, gridClosest1[si][sj]);                  
//             ans=max(ans,currentmin);
//             return;  
//         }
//         if(si<0 || sj<0 || si>=n || sj>=n || visited[si][sj] == 1){
//             return;
//         }
//         visited[si][sj]=1;
//         currentmin=min(currentmin, gridClosest1[si][sj]);
        
//         dfs(n,grid,gridClosest1,si+1,sj,currentmin,visited,ans);
//         dfs(n,grid,gridClosest1,si-1,sj,currentmin,visited,ans);
//         dfs(n,grid,gridClosest1,si,sj+1,currentmin,visited,ans);
//         dfs(n,grid,gridClosest1,si,sj-1,currentmin,visited,ans);
//     }

//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         int n=grid.size();
//         // find manhattan distance of each block in advance..
//         vector<vector<int>> gridClosest1(n, vector<int>(n,0));

//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 int closest1=2*n;
//                 for(int k=0; k<n; k++){
//                     for(int l=0; l<n; l++){
//                         if(grid[k][l] == 0){
//                             continue;
//                         }
//                         int currentDist= abs(j-l) + abs(i-k);
//                         closest1= min(closest1, currentDist);
//                     }
//                 }
//                 gridClosest1[i][j]= closest1;
//             }
//         }
//         // return 0;
//         int ans=0;
//         vector<vector<int>> visited(n,vector<int>(n,0));
//         int currentmin= 2*n;
//         dfs(n,grid,gridClosest1,0,0,currentmin,visited,ans);

//         return ans;

//     }
// };

class Solution {

    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, 1, -1};
    
    bool bfs(vector<vector<int>> &dist, int sf)
    {
        if(dist[0][0]<sf) return false;
        int n=dist.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        q.push({0, 0});
        vis[0][0]=true;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==n-1 && y==n-1) return true;
            for(int k=0; k<4; k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<n && dist[nx][ny]>=sf && !vis[nx][ny])
                {
                    q.push({nx, ny});
                    vis[nx][ny]=true;
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) 
            {
                if(grid[i][j]==1) 
                {
                    dist[i][j]=0;
                    q.push({i, j});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int k=0; k<4; k++)
                {
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny])
                    {
                        q.push({nx, ny});
                        vis[nx][ny]=true;
                        dist[nx][ny]=1+dist[x][y];
                    }
                }
            }
        }
        int low=0, high=1e9, ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(bfs(dist, mid))
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};