class Solution {
public:
    void recur(vector<int>& nums, int size, vector<vector<int>>& ans, vector<int> ds, int index){
        
        ans.push_back(ds);

        for(int i=index; i<size; i++){
            if(i==index){
                ds.push_back(nums[i]);
                recur(nums,size,ans,ds,i+1);
                ds.pop_back();
                continue;
            }

            if(nums[i] != nums[i-1]){
                ds.push_back(nums[i]);
                recur(nums,size,ans,ds,i+1);
                ds.pop_back();
                continue;
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size=nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        recur(nums,size,ans,ds,0);
        return ans;
    }
};