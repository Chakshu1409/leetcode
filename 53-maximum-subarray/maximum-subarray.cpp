class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();

        int ans=INT_MIN;
        int currentPrefixSum=0;
        int minPrefixSum=0;

        for(int i=0; i<size; i++){
            currentPrefixSum+=nums[i];
            ans = max(ans, currentPrefixSum-minPrefixSum);
            minPrefixSum = min(minPrefixSum, currentPrefixSum);
        }

        return ans;
    }
};