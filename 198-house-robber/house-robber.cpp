class Solution {
public:
    int rob(vector<int>& nums) {
        
        int size=nums.size();

        vector<vector<int>> dp(size, vector<int>(2,0));

        int first=0;
        int second=nums[0];
        for(int i=1; i<size; i++){
            int temp = max(nums[i] + first, second);
            first = max(first, second); 
            second=temp;
        }
        return max(first,second);
    }
};