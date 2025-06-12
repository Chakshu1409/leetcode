class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp(n,0);

        for(int i=0; i<n; i++){
            dp[i] = matrix[0][i];
        }
        for(int i=1; i<n; i++){
            vector<int> tempDp(n,0);
            for(int j=0; j<n; j++){
                if(j==0){
                    tempDp[j]=matrix[i][j] + min(dp[j],dp[j+1]);
                }
                else if(j==n-1){
                    tempDp[j]=matrix[i][j] + min(dp[j],dp[j-1]);
                }
                else{
                    tempDp[j] = matrix[i][j] + min(dp[j], min(dp[j-1], dp[j+1]));
                }
            }
            dp=tempDp;
        }   
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(mini, dp[i]);
        }   
        return mini;
    }
};