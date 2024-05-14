class Solution {
public:
    int helper(vector<int>& values, int size, int si, int ei, vector<vector<int>>& dp){
        // if(ei-si < 2){
        //     return values[si]*values[si+1]*values[(si+2)%size];
        // }
        if(ei-si == 2){
            return values[si]*values[si+1]*values[si+2];
        }
        if(ei-si == 3){
            int first=values[si]*values[si+1]*values[si+2] + values[si+2]*values[si+3]*values[si];
            int second=values[si+1]*values[si+2]*values[si+3] + values[si+3]*values[si]*values[si+1];
            return min(first,second);
        }
        if(dp[si][ei] !=-1){
            return dp[si][ei];
        }
        int ans=INT_MAX;
        for(int i=si+1; i<ei; i++){
            int first=0;
            if(i!=si+1){
                first=helper(values, size, si, i,dp);
            }
            
            int second=0;
            if(i!=ei-1){
                second=helper(values, size, i, ei,dp);
            }

            ans=dp[si][ei] = min(ans, values[si]*values[ei]*values[i] + first+second);
        }

        return ans;


    }

    int minScoreTriangulation(vector<int>& values) {
        int size=values.size();

        int si=0;
        int ei=size-1;
        // values.push_back(values[0]);
        vector<vector<int>> dp(size, vector<int>(size, -1));
        return helper(values, size, si, ei,dp);

    } 
};