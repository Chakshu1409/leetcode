class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size=nums.size();

        int totalSum=0;

        for(int i=0; i<size; i++){
            totalSum+=nums[i];
        }

        int k=0;
        if(totalSum%2){
            return false;
        }
        
        k=totalSum/2;
        for(int i=0; i<size; i++){
            if(nums[i] > k){
                return false;
            }
        }
        // cout<<'f';
        vector<vector<bool>> dp(size, vector<bool>(k+1,false));

        for(int i=0; i<size; i++){
            dp[i][0]=true;
        }
        dp[0][nums[0]]=true;

        for(int i=1; i<size; i++){
            for(int j=1; j<=k; j++){
                // notTake
                int notTake=dp[i-1][j];

                int take=false;
                if(j>=nums[i]){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        for(int i=0; i<size; i++){
            if(dp[i][k]){
                return true;
            }
        }
        return false;
    }
};