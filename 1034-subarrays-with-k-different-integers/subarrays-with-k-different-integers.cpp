class Solution {
public:
    int helper(vector<int>& nums, int k){
        int size=nums.size();
        int i=0; 
        int j=0; 
        int ans=0;
        unordered_map<int,int> map;
        int unique=0;
        while(j<size){
            while(j<size && unique<k){
                if(map[nums[j]]==0){
                    unique++;
                }
                map[nums[j]]++;
                j++;
            }
            
            while(i<j && unique>=k){
                ans+= size-j+1;
                if(map[nums[i]] == 1){
                    unique--;
                }
                map[nums[i]]--;
                i++;
            }
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {        
        int kplus1= helper(nums,k+1);
        int kplus0= helper(nums,k);
        cout<<kplus0<<" "<<kplus1<<endl;
        return kplus0-kplus1;
        
    }
};