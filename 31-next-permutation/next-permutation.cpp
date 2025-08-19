class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();

        int ind=-1;
        for(int i=size-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int indToSwap=size-1;
        for(int i=ind+1; i<size; i++){
            if(nums[i] <= nums[ind]){
                break;
            }
            indToSwap=i;
        }

        swap(nums[ind], nums[indToSwap]);

        reverse(nums.begin()+ind+1, nums.end());

        return;
    }
};