class Solution {
public:
    int helper(vector<int>& prices, int size, int index, int buy, vector<vector<int>>& dp){
        if(index==size){
            return 0;
        }
        if(dp[index][buy] !=-1){
            return dp[index][buy];
        }
        int notTake=helper(prices,size,index+1,buy,dp);
        int take=0;

        if(buy==0){
            take=prices[index] + helper(prices,size,index+1,1,dp);
        }
        else{
            take=-prices[index] + helper(prices,size,index+1,0,dp);
        }

        return dp[index][buy]=max(notTake,take);
    }

    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int index=0;
        int buy=1;
        int profit=0;
        vector<vector<int>> dp(size, vector<int>(2,-1));
        return helper(prices,size,index,buy,dp);
    }
};