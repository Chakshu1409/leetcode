class Solution {
public:
    int rob(vector<int>& nums) {
        
        int size=nums.size();

        vector<vector<int>> dp(size, vector<int>(2,0));

        dp[0][0]=0;
        dp[0][1]=nums[0];
        cout<<dp[0][0]<<" "<<dp[0][1]<<endl;
        for(int i=1; i<size; i++){
            dp[i][1] = max(nums[i] + dp[i-1][0], dp[i-1][1]);
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]); 
        }
        return max(dp[size-1][1], dp[size-1][0]);
    }
};