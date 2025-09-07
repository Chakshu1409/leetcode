class Solution {
public:
    int recurr(vector<int>& prices, int size, int ind, int sell, vector<vector<int>>& dp){
        if(ind == -1 && sell == 0){
            return 0-1e9;
        }
        if(ind == -1){
            return 0;
        }

        if(dp[ind][sell]!= -1){
            return dp[ind][sell];
        }

        int notExecute = recurr(prices, size, ind-1, sell, dp);

        int execute=-1;
        if(sell == 1){
            execute = prices[ind] + recurr(prices, size, ind-1, 0, dp);
        }
        else{
            execute = -prices[ind] + recurr(prices, size, ind-1, 1, dp);
        }

        return dp[ind][sell] = max(execute, notExecute);
    }

    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int sell = 1;
        vector<vector<int>> dp(size, vector<int>(2, -1));
        return max(0,recurr(prices, size, size-1, sell, dp));
    }
};