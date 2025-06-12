class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int size=coins.size();

        sort(coins.begin(),coins.end());
        
        vector<vector<int>> dp(size, vector<int>(amount+1, 1e9));

        for(int i=0; i<size; i++){
            dp[i][0]=0;
        }

        for(int i=1; i<=amount; i++){
            if(i%coins[0] == 0){
                dp[0][i] = i/coins[0];
            }
        }

        for(int i=1; i<size; i++){
            for(int j=0; j<=amount; j++){
                int notTake=dp[i-1][j];

                int take=1e9;
                if(j>=coins[i]){
                    take=1+dp[i][j-coins[i]];
                }
                dp[i][j] = min(take,notTake);
            }
        }
        if(dp[size-1][amount] == 1e9){
            return -1;
        }
        return dp[size-1][amount];
    }
};