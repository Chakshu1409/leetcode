class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size=nums.size();

        int i=0;
        int j=size-1;

        if(size==1){
            return 0;
        }
        while(i<j){
            int mid= i+(j-i)/2;

            if((mid == 0 || nums[mid]>nums[mid-1]) && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid] > nums[mid+1]){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return j;
    }
};