class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int i=0;
        int j=0;

        while(j<size){
            if(nums[i] != nums[j]){
                swap(nums[i+1], nums[j]);
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i+1;
    }
};