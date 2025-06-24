class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();

        int index=-1;

        for(int i=size-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){

        }

        sort(nums.begin()+index+1, nums.end());
        if(index==-1){
            return;
        }
        for(int i=index+1; i<size; i++){
            if(nums[index] < nums[i]){
                swap(nums[index],nums[i]);
                break;
            }
        }
        return;
    }
};