class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size= nums.size();

        int i=0;
        int countZero=0;
        int ans=0;
        int j=i;
        while(i<size){
            while(j<size && !(nums[j]==0 && countZero==k)){
                if(nums[j] == 0){
                    countZero++;
                }
                j++;
            }
            ans= max(ans, j-i);
            if(nums[i] == 0){
                countZero--;
            }
            i++;
        }
        return ans;
    }
};