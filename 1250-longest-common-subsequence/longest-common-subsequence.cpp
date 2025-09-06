class Solution {
public:

    int recurr(string& text1, string& text2, int size1, int size2, int ind1, int ind2, vector<vector<int>>& dp){

        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }


        if(text1[ind1] == text2[ind2]){
            return 1 + recurr(text1, text2, size1, size2, ind1-1, ind2-1,dp);
        }

        int first= recurr(text1, text2, size1, size2, ind1-1, ind2,dp);
        int second = recurr(text1, text2, size1, size2, ind1, ind2-1, dp);
        int third = recurr(text1, text2, size1, size2, ind1-1, ind2-1, dp);

        return dp[ind1][ind2] = max(first, max(second, third));


    }

    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size();
        int size2=text2.size();
        vector<vector<int>> dp(size1, vector<int>(size2, -1));
        return recurr(text1, text2, size1, size2, size1-1, size2-1, dp);
    }
};