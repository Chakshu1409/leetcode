class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();

        vector<vector<int> > dp(size, vector<int>(2,0));

        int first=nums[0];
        int second=nums[0];

        for(int i=2; i<size-1; i++){
            int temp= max(first,second);
            second= max(nums[i]+first, second);
            first=temp;
        }
        int includeFirst=max(first,second);

        first=0;
        second=0;

        for(int i=1; i<size; i++){
            int temp=max(first,second);
            second=max(nums[i]+first, second);
            first=temp;
        }
        int excludeFirst=max(first,second);

        return max(includeFirst, excludeFirst);
    }
};