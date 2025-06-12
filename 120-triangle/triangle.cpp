class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int numRows=triangle.size();

        vector<int> dp(numRows,0);
        dp[0]=triangle[0][0];

        for(int i=1; i<numRows; i++){
            vector<int> tempDp(numRows,0);
            for(int j=0; j<=i; j++){
                if(j==0){
                    tempDp[j] = dp[j] + triangle[i][j];
                }
                else if(j==i){
                    tempDp[j] = dp[j-1] + triangle[i][j];
                }
                else{
                    tempDp[j] = triangle[i][j] + min(dp[j],dp[j-1]);
                }
            }
            dp=tempDp;
        }

        int ans= INT_MAX;
        for(int i=0; i<numRows; i++){
            ans=min(ans, dp[i]);
        }
        return ans;
        
    }
};