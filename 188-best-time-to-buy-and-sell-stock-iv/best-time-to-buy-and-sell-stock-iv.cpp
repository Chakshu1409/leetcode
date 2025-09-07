class Solution {
public:
    int recurr(vector<int>& prices, int& size, int ind, int sell, vector<vector<vector<int>>>& dp, int count){
        if(count == -1 || (ind == -1 && sell == 0)){
            return 0-1e9;
        }
        if(ind == -1){
            return 0;
        }

        if(dp[ind][sell][count]!= -1){
            return dp[ind][sell][count];
        }

        int notExecute = recurr(prices, size, ind-1, sell, dp, count);

        int execute=-1;
        if(sell == 1){
            execute = prices[ind] + recurr(prices, size, ind-1, 0, dp, count-1);
        }
        else{
            execute = -prices[ind] + recurr(prices, size, ind-1, 1, dp, count);
        }

        return dp[ind][sell][count] = max(execute, notExecute);
    }

    int maxProfit(int k, vector<int>& prices) {
        int size=prices.size();
        int sell = 1;
        int count = k;
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return max(0,recurr(prices, size, size-1, sell, dp, count));
    }
};