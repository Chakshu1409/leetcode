class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int level=0;
        int n=grid.size();
        vector<vector<int>> visited(n, vector<int>(n,0));

        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        if(q.size() == n*n){
            return -1;
        }

        while(!q.empty()){
            int size=q.size();
            while(size--){
                int rowIndex=q.front().first;
                int colIndex=q.front().second;
                q.pop();
                if(rowIndex<0 || rowIndex>=n || colIndex<0 || colIndex>=n || visited[rowIndex][colIndex] == 1){
                    continue;
                }
                visited[rowIndex][colIndex]=1;

                q.push({rowIndex+1 , colIndex});
                q.push({rowIndex-1 , colIndex});
                q.push({rowIndex , colIndex+1});
                q.push({rowIndex , colIndex-1});

            }
            level++;
        }
        if(level==0){
            return -1;
        }
        return level-2;
    }
};