// class Solution {
// public:
//     int helper(vector<vector<int>>& grid, int i1, int i2, int j1, int j2){
//         if(i2>=grid.size() || i1>=grid.size() || j1>=grid.size() || j2>=grid.size()){
//             return -1e8;
//         }

//         if(grid[i1][j1] == -1 || grid[i2][j2] == -1){
//             return -1e8;
//         }

//         if(i1==grid.size()-1 && j1==grid[0].size()-1){
//             return grid[i1][j1];
//         }

//         int one=0;
//         int two=0;
//         int three=0;
//         int four=0;
//         if(i1==i2 && j1==j2){
//             one=grid[i1][j1]+helper(grid,i1+1,i2+1,j1,j2);
//             two=grid[i1][j1]+helper(grid,i1+1,i2,j1,j2+1);
//             three=grid[i1][j1]+helper(grid,i1,i2+1,j1+1,j2);
//             four=grid[i1][j1]+helper(grid,i1+1,i2,j1,j2+1);
//         }
//         else{
//             one=grid[i1][j1]+grid[i2][j2]+helper(grid,i1+1,i2+1,j1,j2);
//             two=grid[i1][j1]+grid[i2][j2]+helper(grid,i1+1,i2,j1,j2+1);
//             three=grid[i1][j1]+grid[i2][j2]+helper(grid,i1,i2+1,j1+1,j2);
//             four=grid[i1][j1]+grid[i2][j2]+helper(grid,i1+1,i2,j1,j2+1);
//         }

//         return max(max(one,two),max(three,four));
//     }


//     int cherryPickup(vector<vector<int>>& grid) {
//         int i1=0;
//         int i2=0;
//         int j1=0;
//         int j2=0;

//         return max(0,helper(grid,i1,i2,j1,j2));
//     }
// };

class Solution {
public:

    int solve(int i1,int j1,int i2,int j2,vector<vector<int>>& grid,int n,
            vector<vector<vector<vector<int>>>>&dp){
        if(i1 >= n || i2 >= n || j1 >= n || j2 >= n 
        || grid[i1][j1] == -1 || grid[i2][j2] == -1){
            return -1e9;
        }
        if(i1 == n-1 && j1 == n-1 ){
            if(grid[i1][j1] == 1){
                return 1;
            }
            return 0;
        }
        if(dp[i1][j1][i2][j2] != -1)return dp[i1][j1][i2][j2];
        int ans = 0;

        if(i1 == i2 && j1 == j2){
            if(grid[i1][j1] == 1){
                ans++;
            }
        }
        if(i1 != i2 || j1 != j2){
            if(grid[i1][j1] == 1){
                ans++;
            }
            if(grid[i2][j2] == 1){
                ans++;
            }
        }
        int cnt1 = solve(i1+1,j1,i2+1,j2,grid,n,dp);
        int cnt2 = solve(i1+1,j1,i2,j2+1,grid,n,dp);
        int cnt3 = solve(i1,j1+1,i2+1,j2,grid,n,dp);
        int cnt4 = solve(i1,j1+1,i2,j2+1,grid,n,dp);

        return dp[i1][j1][i2][j2] = ans + max({cnt1,cnt2,cnt3,cnt4});
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        int ans = solve(0,0,0,0,grid,n,dp);
        if(ans < 0)return 0;
        return ans;
    }
};