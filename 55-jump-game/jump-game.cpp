class Solution {
public:

    bool canJump(vector<int>& nums) {
        int size=nums.size();
        int reachedIndex=0;

        if(size==1){
            return true;
        }
        if(nums[0] == 0){
            return false;
        }

        for(int i=0; i<size-1; i++){
            if(reachedIndex < i){
                return false;
            }
            reachedIndex = max(reachedIndex, nums[i]+i);
            if(reachedIndex>=size-1){
                return true;
            }

        }
        return false;
    }
};