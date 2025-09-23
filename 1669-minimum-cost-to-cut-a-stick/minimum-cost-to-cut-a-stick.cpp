class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int size=cuts.size();

        vector<vector<int>> dp(size, vector<int>(size, 0));

        for(int i=size-2; i>=1; i--){
            for(int j=1; j<=size-2; j++){
                if(i>j) continue;

                int mini=INT_MAX;
                for(int k=i; k<=j; k++){
                    mini = min(mini, dp[i][k-1] + dp[k+1][j] + cuts[j+1]-cuts[i-1]);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][size-2];
    }
};