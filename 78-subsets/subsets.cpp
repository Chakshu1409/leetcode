class Solution {
public:
    void recurr(vector<int>& nums, int index, int size, vector<int> ds, vector<vector<int>>& ans){
        if(index==size){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        recurr(nums,index+1, size, ds,ans);
        ds.pop_back();
        recurr(nums,index+1,size,ds,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        int size=nums.size();

        int index=0;
        vector<vector<int>> ans;
        recurr(nums,index,size,ds,ans); 
        return ans;

    }
};