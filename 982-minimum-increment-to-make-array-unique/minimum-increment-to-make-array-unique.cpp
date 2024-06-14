class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int size=nums.size();
        // unordered_map<int,int> map;
        // for(int i=0; i<size; i++){
        //     map[nums[i]]++;
        // }
        int current=0;
        sort(nums.begin(),nums.end());
        while(current < nums[0]){
            current++;
        }
        int ans=0;
        for(int i=0; i<size;){
            ans+=current-nums[i];
            i++;
            current++;
            if(i==size){
                break;
            }
            while(current < nums[i]){
                current++;
            }
        }

        return ans;
        

    }
}; 