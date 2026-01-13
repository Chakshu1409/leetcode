class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
        int i=0;
        int j=0;

        while(j<size){
            if(nums[j]!=0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else{
                j++;
            }
        }
    }
};