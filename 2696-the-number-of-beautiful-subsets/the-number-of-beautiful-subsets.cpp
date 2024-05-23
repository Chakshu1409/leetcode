class Solution {
public:
    void traverse(vector<int>& nums, int size, int si, int k, unordered_map<int,int>& map, int& ans){  
        if(si==size){
            ans++;
            return;
        }

        traverse(nums,size,si+1,k,map,ans);
        if(map[nums[si] - k] == 0  &&  map[nums[si] + k] == 0){
            map[nums[si]]++;
            traverse(nums,size,si+1,k,map,ans);
            map[nums[si]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int size=nums.size();
        int ans=0;
        unordered_map<int,int> map;

        traverse(nums,size,0,k,map,ans);
        return ans-1;
    }
};