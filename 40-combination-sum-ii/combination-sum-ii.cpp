class Solution {
public:

    void recurr(vector<int>& candidates, int target, int size, int index, vector<vector<int>>& ans, vector<int>& ds){

        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(target<0){
            return;
        }

        for(int i=index; i<size; i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            ds.push_back(candidates[i]);
            recurr(candidates, target-candidates[i], size, i+1, ans, ds);
            ds.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int size=candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        recurr(candidates, target, size, 0, ans, ds);

        return ans;
    }
};