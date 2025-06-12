class Solution {
public:
    void recurr(vector<int>& nums, int size, int target, int index, int& ans){
        if(index == size && target == 0){
            ans++;
            return;
        }
        if(index == size){
            return;
        }

        recurr(nums,size, target-nums[index], index+1, ans);
        recurr(nums, size, target+nums[index], index+1, ans);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int size=nums.size();
        int ans=0;
        recurr(nums,size,target,0,ans);
        return ans;
    }
};