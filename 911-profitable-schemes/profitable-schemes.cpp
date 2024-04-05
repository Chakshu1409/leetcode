#define mod 1000000007
class Solution {
public:
    long long helper(int size, vector<int>& group, vector<int>& profit, int n, int minProfit, int index, vector<vector<vector<int>>>& dp){
        if(n<0){
            return 0;
        }
        if(minProfit<=0){
            minProfit=0;
        }
        if(index==size){
            if(minProfit==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[n][index][minProfit] != -1){
            return dp[n][index][minProfit];
        }

        long long take=helper(size,group,profit,n-group[index], minProfit-profit[index],index+1,dp);
        long long notTake=helper(size,group,profit,n,minProfit,index+1,dp);

        return dp[n][index][minProfit]=(take+notTake)%mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int index=0;
        int size=group.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(size+1, vector<int>(minProfit+1,-1)));
        return helper(size,group,profit,n,minProfit,index,dp)%mod;
    }
};