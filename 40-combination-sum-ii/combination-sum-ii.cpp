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

        for(int i=index; i<size; i++){
            if(i==index || nums[i]!=nums[i-1]){
                if(nums[i] <= target){
                    ds.push_back(nums[i]);
                    recurr(nums, target-nums[i], size, i+1, ans, ds);
                    ds.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        int size=candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;

        recurr(candidates, target, size, 0, ans, ds);

        return ans;
    }
};