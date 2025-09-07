class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int numRows=mat.size();
        int numCols=mat[0].size();

        vector<vector<int>> visited(numRows, vector<int>(numCols, 0));

        queue<vector<int>> q;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<numCols; j++){
                if(mat[i][j] == 0){
                    q.push({i,j,0});
                    visited[i][j] = 1;
                }
            }
        }

        vector<vector<int>> ans(numRows, vector<int>(numCols, 0));

        while(!q.empty()){
            int currI=q.front()[0];
            int currJ=q.front()[1];
            int currDist=q.front()[2];

            q.pop();
            ans[currI][currJ] = currDist;

            vector<int> dI={0,0,1,-1};
            vector<int> dJ={1,-1,0,0};

            for(int i=0; i<4; i++){
                int newI=currI+dI[i];
                int newJ=currJ+dJ[i];

                if(newI>=0 && newI<numRows && newJ>=0 && newJ<numCols && visited[newI][newJ] == 0){
                    visited[newI][newJ] = 1;
                    q.push({newI,newJ,currDist+1});
                }
            }
        }

        return ans;
    }
};