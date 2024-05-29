class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size=nums.size();
        unordered_set<int> se;
        if(size==0){
            return 0;
        }
        for(int i=0; i<size; i++){
            se.insert(nums[i]);
        }
        int ans=1;
        for(int i=0; i<size; i++){
            if(se.find(nums[i] - 1) == se.end()){
            int current=nums[i]+1;
            int temp=1;
            while(se.find(current) != se.end()){
                temp++;
                current++;
            }
            ans=max(temp,ans);
        }
        }
        
        return ans;

    }   
};