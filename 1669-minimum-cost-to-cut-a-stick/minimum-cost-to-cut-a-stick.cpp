class Solution {
public:
    int helper(int n, vector<int>& cuts, int si, int ei,vector<vector<int>>& dp){
        if(ei-si == 1){
            return 0;
        }
        if(dp[si][ei]!=-1){
            return dp[si][ei];
        }

        int ans=INT_MAX;
        for(int i=si+1; i<ei; i++){
            int first=helper(n,cuts,si,i,dp);
            int second=helper(n,cuts,i,ei,dp);
            
            ans= min(ans, first+second);

        }
        return dp[si][ei]=ans+cuts[ei]-cuts[si];
    }

    int minCost(int n, vector<int>& cuts) {
        int size=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<int> cutsNew;
        cutsNew.push_back(0);
        for(int i=0; i<size; i++){
            cutsNew.push_back(cuts[i]);
        }
        cutsNew.push_back(n);
        
        vector<vector<int>> dp(size+2, vector<int>(size+2, -1));

        return helper(n,cutsNew,0,size+1,dp);
    }
};