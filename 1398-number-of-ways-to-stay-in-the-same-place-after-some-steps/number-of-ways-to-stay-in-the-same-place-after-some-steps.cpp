const int mod=1e9+7;
class Solution {
public:
    long long helper(int steps, int arrLen, int index, vector<vector<int>>& dp){
        if(index>min(500,arrLen-1) || index<0){
            return 0;
        }
        if(steps==0){
            if(index==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[index][steps] != -1){
            return dp[index][steps];
        }

        long long ans=0;
        ans+= helper(steps-1, arrLen, index-1,dp);
        // ans%=mod;
        ans+=helper(steps-1, arrLen, index+1,dp);
                // ans%=mod;

        ans+= helper(steps-1, arrLen, index,dp);
                // ans%=mod;


        return dp[index][steps] = ans%mod;
    }

    int numWays(int steps, int arrLen) {
        int index=0;
        vector<vector<int>> dp(501, vector<int>(501,-1));
        return (helper(steps,arrLen,index,dp))%1000000007;
    }
};