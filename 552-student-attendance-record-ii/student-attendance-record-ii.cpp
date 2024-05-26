#define MOD 1000000007
class Solution {
public:
    long long helper(int n, int index, int count1, int count2, vector<vector<vector<long long>>>& dp){
        if(count1>1 || count2>2){
            return 0;
        }
        if(index==n){
            return 1;
        }
        if(dp[index][count1][count2] != -1){
            return dp[index][count1][count2];
        }

        long long ans=0;

        long long first=helper(n,index+1,count1,0,dp);
        ans = (ans+first)%MOD;
        long long second=helper(n,index+1,count1+1,0,dp);
        ans = (ans+second)%MOD;
        long long third=helper(n,index+1,count1,count2+1,dp);
        ans = (ans+third)%MOD;

        return dp[index][count1][count2]=ans;

    }

    int checkRecord(int n) {
        int count1=0;
        int count2=0;
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(2,vector<long long>(3,-1)));
        long long ans= helper(n,0,count1,count2,dp);

        int finalAns=ans%MOD;

        return finalAns;

    }
};