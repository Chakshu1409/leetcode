class Solution {
public:
    int findMin(vector<int>& nums) {
        int size=nums.size();

        int si=0;
        int ei=size-1;
        int ans=INT_MAX;

        while(si <= ei){
            int mid= si + (ei-si)/2;
            
            if(nums[mid] >= nums[0]){// left half sorted
                ans=min(ans, nums[si]);
                si=mid+1;
            }
            else{// right half sorted
                ans=min(ans, nums[mid]);
                ei=mid-1;
            }
        }

        return ans;
    }
};