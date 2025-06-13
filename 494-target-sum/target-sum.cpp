class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int size=nums.size();
        int ans=0;

        int totalSum=0;
        for(int i=0; i<size; i++){
            totalSum+=nums[i];
        }

        if(target>totalSum || target< 0-totalSum){
            return 0;
        }
        
        vector<int> dp(2*totalSum + 1,0);

        dp[totalSum-nums[0]]++;
        dp[totalSum+nums[0]]++;

        // for(int i=0; i<=2*totalSum; i++){
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;

        for(int i=1; i<size; i++){
            
            vector<int> tempDp(2*totalSum+1,0);
            for(int j=0; j<=2*totalSum; j++){
                int realNum=j-totalSum;
                if(realNum+nums[i]+totalSum <= 2*totalSum){
                    tempDp[j] += dp[realNum+nums[i]+totalSum];
                }
                if(realNum-nums[i]+totalSum >= 0){
                    tempDp[j] += dp[realNum-nums[i]+totalSum];
                }
            }
            // for(int k=0; k<=2*totalSum; k++){
            //     cout<<tempDp[k]<<" ";
            // }
            // cout<<endl;
            dp=tempDp;
        }
        return dp[target+totalSum];
    }
};