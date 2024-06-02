class Solution {
public:
    void helper(vector<int>& nums, int index, int size, vector<vector<int>>& ans, vector<int> ds){
        if(index==size){
            ans.push_back(ds);
            return;
        }
        ans.push_back(ds);
        for(int i= index; i<size; i++){
            if(i!=index && nums[i] == nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            helper(nums,i+1,size,ans,ds);
            ds.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int index=0;
        int size=nums.size();
        vector<int> ds;
        helper(nums,index,size,ans,ds);
        return ans;
    }
};