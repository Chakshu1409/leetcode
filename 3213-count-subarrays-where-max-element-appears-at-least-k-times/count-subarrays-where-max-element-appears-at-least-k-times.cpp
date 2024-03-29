class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int size=nums.size();
        for(int i=0; i<size; i++){
            maxi=max(nums[i],maxi);
        }

        vector<int> prefix;
        int count=0;
        prefix.push_back(count);
        for(int i=0; i<size; i++){
            if(nums[i] == maxi){
                count++;
            }
            prefix.push_back(count);
        }

        int i=1; 
        int j=1;
        long long ans=0; 
        while(1){
            while(j<size && prefix[j]-prefix[i-1] < k){
                j++;
            }
            while(i<=j && prefix[j]-prefix[i-1] >= k){
                ans+= size-j+1;
                i++;
            }

            if(j==size){
                break;
            }


        }
        return ans;
    }
};