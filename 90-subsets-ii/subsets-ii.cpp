class Solution {
public:
    void recurr(vector<int>& nums, int size, int index, vector<vector<int>>& ans, vector<int>& ds){
        ans.push_back(ds);    
        for(int i=index; i<size; i++){
            // recurr(nums, size, i+1, ans, ds);
            if(i==index || nums[i]!=nums[i-1]){
                ds.push_back(nums[i]);
                recurr(nums, size, i+1, ans, ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size=nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        recurr(nums, size, 0, ans, ds);

        return ans;
    }
};