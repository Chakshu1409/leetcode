class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0;

        while(i<size){
            int j=i+1;
            int k=size-1;
            int req=0-nums[i];
            int numi=nums[i];
            while(j<k){
                if(nums[j]+nums[k] > req){
                    k--;
                }
                else if(nums[j] + nums[k] < req){
                    j++;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int numj=nums[j];
                    int numk=nums[k];
                    while(j<k && nums[j] == numj) j++;
                    while(j<k && nums[k] == numk) k--; 
                }
            }
            while(i<size && nums[i]==numi) i++;
        }
        return ans;
    }
};