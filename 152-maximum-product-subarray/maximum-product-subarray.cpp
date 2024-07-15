class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size=nums.size();

        int ans=INT_MIN;

        int i=0;
        int j=0;

        while(j<size){

            if(nums[j] == 0){
                j++;
                i=j;

                ans=max(ans,0);
                continue;
            }
            int current=1;

            while(j<size && nums[j] !=0){
                j++;
            }
            // if(j<size && nums[j] == 0){
            //     ans= max(ans,0);
            // }
            int current1=1;
            int current2=1;

            for(int k=i; k<j; k++){
                if(current1 >= 1e8){
                    break;
                }
                current1*=nums[k];
                ans=max(ans, current1);
            }
            for(int k=j-1; k>=i; k--){
                if(current2>1e8){
                    break;
                }
                current2*=nums[k];
                ans=max(ans, current2);
            }
        }
        return ans;

    }
};