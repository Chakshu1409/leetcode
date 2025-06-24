class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size=nums.size();

        vector<int> ans(size,0);

        int ii=0; 
        int j=1;
        for(int i=0; i<size; i++){
            if(nums[i] > 0){
                ans[ii]=nums[i];
                ii+=2;
            }
            else{
                ans[j]=nums[i];
                j+=2;
            }
        }
        return ans;
    }
};