class Solution {
public:
    int recurr(vector<vector<int>>& grid, int numRows, int numCols, int currRow, int currCol, vector<vector<int>>& dp){

        if(currRow == 0 && currCol == 0){
            return grid[0][0];
        }

        int top= INT_MAX;

        if(dp[currRow][currCol] != -1){
            return dp[currRow][currCol];
        }

        if(currRow > 0){
            top= recurr(grid, numRows, numCols, currRow-1, currCol, dp);
        }

        int left= INT_MAX;

        if(currCol > 0){
            left= recurr(grid, numRows, numCols, currRow, currCol-1, dp);
        }

        return dp[currRow][currCol] = grid[currRow][currCol] + min(left, top);

    }

    int minPathSum(vector<vector<int>>& grid) {
        int numRows=grid.size();
        int numCols=grid[0].size();
        vector<vector<int>> dp(numRows, vector<int>(numCols, -1));
        return recurr(grid, numRows, numCols, numRows-1, numCols-1, dp);
    }
};