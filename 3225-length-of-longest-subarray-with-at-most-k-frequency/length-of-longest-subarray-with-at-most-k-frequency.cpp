class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int size=nums.size();
        int i=0; 
        int j=0;
        unordered_map<int,int> freq;
        int ans=INT_MIN;
        while(j<size){
            if(freq[nums[j]]<k){
                freq[nums[j]]++;
                j++;
                ans=max(ans,j-i);
            }
            else{
                while(i<j && nums[i]!=nums[j]){
                    freq[nums[i]]--;
                    i++;
                }
                i++;
                j++;
            }
        }
        
        return ans;
    }
};