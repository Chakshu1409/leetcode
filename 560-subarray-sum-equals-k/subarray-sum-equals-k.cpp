class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size=nums.size();
        unordered_map<int,int> map;
        map[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0; i<size; i++){
            sum+=nums[i];
            ans+=map[sum-k];
            map[sum]++;
        }
        return ans;
    }
};