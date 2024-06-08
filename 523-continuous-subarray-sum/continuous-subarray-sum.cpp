class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size=nums.size();
        unordered_map<int,int> map;
        int sum=0;
        for(int i=0; i<size; i++){
            sum+=nums[i];
            if(i!=0 && sum%k==0){
                // cout<<"HI";
                return true;
            }
            if(i+1-map[sum%k] > 1 && map[sum%k]!=0){
                // cout<<"hi";
                return true;
            }
            if(map[sum%k] == 0){
                map[sum%k]=i+1;
            }
            
        }
        return false;
    }
};