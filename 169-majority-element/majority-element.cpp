class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size();
        int count=0;
        int current=-1;
        for(int i=0; i<size; i++){
            if(current == nums[i]){
                count++;
            }
            else{
                if(count > 0){
                    count--;
                }
                else{
                    current=nums[i];
                }
            }
        }
        return current;
    }
};