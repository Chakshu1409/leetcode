class Solution {
public:
    void recurr(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> ds, int size, int index){

        if(target==0){
            ans.push_back(ds);
            return;
        }

        for(int i=index; i<size; i++){
            if(i==index){
                if(candidates[i] <= target){
                    ds.push_back(candidates[i]);
                    recurr(candidates, target-candidates[i], ans, ds, size, index+1);
                    ds.pop_back();
                }
                continue;
            }
            if(candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] <= target){
                ds.push_back(candidates[i]);
                recurr(candidates, target-candidates[i], ans, ds, size, i+1);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int size=candidates.size();

        int index=0;
        sort(candidates.begin(), candidates.end());
        recurr(candidates,target,ans,ds,size,index);
        return ans;
    }
};