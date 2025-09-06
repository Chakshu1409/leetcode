class Solution {
public:

    int recurr(string& word1, string& word2, int size1, int size2, int ind1, int ind2, vector<vector<int>>& dp){

        if(ind1 < 0){
            return ind2+1;
        }
        if(ind2 < 0){
            return ind1+1;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(word1[ind1] == word2[ind2]){
            return recurr(word1, word2, size1, size2, ind1-1, ind2-1, dp);
        }

        int first= 1 + recurr(word1, word2, size1, size2, ind1-1, ind2, dp);
        int second = 1 + recurr(word1, word2, size1, size2, ind1, ind2-1, dp);

        return dp[ind1][ind2] = min(first, second);

    }

    int minDistance(string word1, string word2) {
        int size1=word1.size();
        int size2=word2.size();

        vector<vector<int>> dp(size1, vector<int>(size2, -1));

        return recurr(word1, word2, size1, size2, size1-1, size2-1, dp);
    }
};