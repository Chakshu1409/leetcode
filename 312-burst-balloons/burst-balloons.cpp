class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size=nums.size();
        reverse(nums.begin(), nums.end());
        nums.push_back(1);
        reverse(nums.begin(), nums.end());
        nums.push_back(1);

        vector<vector<int>> dp(size+2, vector<int>(size+2, 0));
        // i want dp[1][size]
        for(int i=1; i<=size; i++){
            dp[i][i]=nums[i]*nums[i+1]*nums[i-1];
        }

        for(int i=size-1; i>=1; i--){
            for(int j=i+1; j<= size; j++){
                
                for(int k=i; k<=j; k++){
                    // cout<<k<<endl;
                    int current = dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1];

                    dp[i][j]=max(dp[i][j], current);
                }
            }
        }

        return dp[1][size];
        
    }
};