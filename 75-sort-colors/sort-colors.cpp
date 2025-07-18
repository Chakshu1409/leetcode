class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size=nums.size();

        int low=0;
        int high=size-1;
        int mid=0;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[high],nums[mid]);
                high--;
            }
        }
        return;
    }
};