class Solution {
public:
    int helper(string& text1, string& text2, int i1, int i2, vector<vector<int>>& dp){
        if(i1==text1.size() || i2==text2.size()){
            return 0;
        }

        if(dp[i1][i2] != -1){
            return dp[i1][i2];
        }

        if(text1[i1] == text2[i2]){
            return dp[i1][i2] = 1+helper(text1, text2,i1+1,i2+1,dp);
        }

        int first=helper(text1,text2,i1+1,i2,dp);
        int second=helper(text1,text2,i1,i2+1,dp);
        int third=helper(text1,text2,i1+1,i2+1,dp);

        return dp[i1][i2]=max(first,max(second,third));

    }

    int longestCommonSubsequence(string text1, string text2) {
        int i1=0;
        int i2=0;
        int size1=text1.size();
        int size2=text2.size();
        vector<vector<int>> dp(size1+1, vector<int>(size2+1,-1));
        return helper(text1,text2,i1,i2,dp);
    }
};