class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int size= nums.size();
        vector<long long> dp(size+1, 0);
        if(size==1){
            return nums[0];
        }
        // subarray ka size ya to 1 hoga ya 2, isse zyyada size vale casses cover ho jaenge
        dp[0]= nums[0];
        dp[1]= max(nums[0] + nums[1] , nums[0]-nums[1]);
        for(int i=2; i<size; i++){
            dp[i]= max(dp[i-1] + nums[i], dp[i-2]+nums[i-1]-nums[i]);
        }
        return dp[size-1];
    }
};