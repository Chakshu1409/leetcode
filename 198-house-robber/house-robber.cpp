class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        int take=nums[0];
        int notTake=0;

        for(int i=1; i<size; i++){
            int temptake= nums[i] + notTake;
            int tempNotTake= max(take, notTake);

            take=temptake;
            notTake= tempNotTake;
        }

        return max(take, notTake);
    }
};