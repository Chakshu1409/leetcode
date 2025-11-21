class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();

        int i=1; 
        int j=1;

        while(j<size){
            if(nums[j] == nums[i-1]){
                j++;
            }
            else{
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
        }
        return i;
    }
};