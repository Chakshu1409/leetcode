class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();

        int i=0; 
        int j=0;

        while(j<size){
            while(j<size && nums[i]==nums[j]){
                j++;
            }
            if(j!=size){
                i++;
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return i+1;
    }
};