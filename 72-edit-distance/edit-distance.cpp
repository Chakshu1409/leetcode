class Solution {
public:

    int helper(string& word1, string& word2, int n, int m, int i1, int i2, vector<vector<int>>& dp){

        if(i1==n){
            return m-i2;
        }

        if(i2==m){
            return n-i1;
        }

        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }

        if(word1[i1] == word2[i2]){
            return dp[i1][i2]=helper(word1,word2,n,m,i1+1,i2+1,dp);
        }

        int replace= 1+helper(word1,word2,n,m,i1+1,i2+1,dp);
        int deletee= 1+helper(word1,word2,n,m,i1+1,i2,dp);
        int insert=1+helper(word1,word2,n,m,i1,i2+1,dp);

        return dp[i1][i2]=min(replace, min(deletee,insert));
    }

    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1)); 
        return helper(word1,word2,n,m,0,0,dp);
    }
};