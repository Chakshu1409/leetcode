class Solution {
public:

    void recurr(vector<int>& nums, int target, int size, int index, vector<vector<int>>& ans, vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        if(index==size){
            return;
        }
        // notTake
        recurr(nums, target, size, index+1, ans, ds);

        if(nums[index] <= target){
            ds.push_back(nums[index]);
            recurr(nums, target-nums[index], size, index, ans, ds);
            ds.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int size=candidates.size();

        vector<vector<int>> ans;
        vector<int> ds;

        recurr(candidates, target, size, 0, ans, ds);

        return ans;
    }
};