class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size=nums.size();
        int i=0;
        int j=size-1;

        while(i<j){
            int mid=(i+j)/2;
            if(mid%2 == 1){
                if(nums[mid] != nums[mid+1]){
                    i=mid+1;
                }
                else{
                    j=mid;
                }
            }
            else{
                if(nums[mid] != nums[mid+1]){
                    j=mid;
                }
                else{
                    i=mid+1;
                }
            }
        }
        return nums[i];
    }
};