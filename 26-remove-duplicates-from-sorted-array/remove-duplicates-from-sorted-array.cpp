class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        int i=0;
        int j=0;
        int k=0;
        while(j<size){
            nums[k]=nums[i];
            while(j<size && nums[j]==nums[i]){
                j++;
            }
            i=j;
            k++;
        }
        

        return k;

        
    }
};