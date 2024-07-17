class Solution {
public:

    int helper(string& text1, string& text2, int n, int m, int i1, int i2, vector<vector<int>>& dp){
        if(i1 == n || i2 == m){
            return 0;
        }

        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }

        int first=0;

        if(text1[i1] == text2[i2]){
            first=1+helper(text1,text2,n,m,i1+1,i2+1,dp);
        }

        int second=helper(text1,text2,n,m,i1+1,i2,dp);
        int third=helper(text1,text2,n,m,i1,i2+1,dp);

        return dp[i1][i2]=max(first, max(second,third));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return helper(text1,text2,n,m,0,0,dp);
    }
};