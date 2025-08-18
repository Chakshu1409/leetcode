class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size=nums.size();

        int i=0;
        int j=0;
        int countZero=0;
        int ans=0;
        while(j<size){
            while(j<size && countZero<=k){
                if(nums[j] == 0){
                    countZero++;
                }
                if(countZero > k){
                    break;
                }
                j++;
            }
            ans=max(ans, j-i);
            if(nums[i] == 0){
                countZero--;
                j++;
            }
            i++;
        }
        return ans;
    }
};