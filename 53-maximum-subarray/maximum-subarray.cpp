class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size=nums.size();

        int ans=INT_MIN;
        int current=0;
        for(int i=0; i<size; i++){
            current+=nums[i];
            ans = max(ans,current);
            if(current<0){
                current=0;
            }
        }
        return ans;
    }
};