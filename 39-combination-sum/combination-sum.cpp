class Solution {
public:
    void recurr(vector<int>& candidates, int target, int index, int size, vector<vector<int>>& ans, vector<int> ds){
        if(index==size && target == 0){
            ans.push_back(ds);
            return;
        }
        if(index==size){
            return;
        }

        recurr(candidates, target, index+1, size,ans, ds);

        if(target >= candidates[index]){
            ds.push_back(candidates[index]);
            recurr(candidates, target-candidates[index], index, size, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int size=candidates.size();
        int index=0;

        recurr(candidates,target,index,size,ans,ds);
        return ans;
    }
};