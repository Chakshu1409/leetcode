class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int size=nums.size();
        unordered_map<int,int> map;
        int sum=0;
        int ans=0;
        for(int i=0; i<size; i++){
            sum+=nums[i];
            int mod=sum%k;
            if(mod<0){
                mod+= k;
            }
            ans+= map[mod];
            
            map[mod]++;

            if(mod==0){
                ans++;
            }
            
            // if(nums[i]%k == 0){
            //     ans++;
            // }
            
        }
        return ans;
    }
};