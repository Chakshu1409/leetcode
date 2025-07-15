class Solution{
    public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int numRow=grid.size();
        int numCol=grid[0].size();

        if(grid[0][0] || grid[numRow-1][numCol-1]) return -1;

        vector<vector<int>> distance(numRow, vector<int>(numCol,1e9));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        distance[0][0]=0;
        while(!pq.empty()){
            int dist=pq.top()[0];
            int currDestI=pq.top()[1];
            int currDestJ=pq.top()[2];


            pq.pop();

            vector<int> di={0,0,1,-1,1,-1,1,-1};
            vector<int> dj={1,-1,0,0,1,-1,-1,1};

            for(int i=0; i<8; i++){
                int currentRowIndex=currDestI+di[i];
                int currentColIndex=currDestJ+dj[i];

                if(currentRowIndex >= 0 && currentColIndex >= 0 && currentRowIndex < numRow && currentColIndex < numCol 
                    && grid[currentRowIndex][currentColIndex] == 0){
                        if(1+dist < distance[currentRowIndex][currentColIndex]){
                            pq.push({dist+1, currentRowIndex, currentColIndex});
                            distance[currentRowIndex][currentColIndex]=1+dist;
                        }
                }
            }
        }

        if(distance[numRow-1][numCol-1] == 1e9) return -1;

        return distance[numRow-1][numCol-1]+1;
    }
};