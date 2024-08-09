class Solution {
public:

    int helper(vector<int>& cuts, int size, int si, int ei, vector<vector<int>>& dp){

        if(si+1 == ei){
            return 0;
        }

        if(dp[si][ei] != -1){
            return dp[si][ei];
        }

        int ans=INT_MAX;
        for(int i=si+1; i<ei; i++){

            int left=helper(cuts,size,si,i,dp);
            int right=helper(cuts,size,i,ei,dp);

            ans= min(ans, left+right+cuts[ei]-cuts[si]);

        }

        return dp[si][ei]=ans;

    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());

        int size=cuts.size();

        vector<vector<int>> dp(size+1, vector<int>(size+1,-1));
        return helper(cuts,size,0,size-1,dp);
    }
};