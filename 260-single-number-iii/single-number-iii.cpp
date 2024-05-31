class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int size=nums.size();
        long long num=0;
        for(int i=0; i<size; i++){
            num = num ^ nums[i];
        }
        // the bit of num which is 1, tells that
        // the two numbers whose xor is this has
        // different bits at this time...

        // segregating all numbers basis on that
        // bit and taking xor differentely of 
        // number with bit 1 at that index and bi
        //t zero at that index..

        // int bitNum=0;
        // while(num>0){
        //     if(num%2 == 1){
        //         break;
        //     }
        //     bitNum++;
        //     num/=2;
        // }

        // int xor1=0;
        // int xor2=0;

        // for(int i=0; i<size; i++){
        //     int x=bitNum;
        //     int num=nums[i];
        //     while(x--){
        //         num/=2;
        //     }
        //     if(num%2 == 1){
        //         xor1 ^= nums[i];
        //     }
        //     else{
        //         xor2 ^= nums[i];
        //     }
        // }

        // vector<int> ans;
        // ans.push_back(xor1);
        // ans.push_back(xor2);

        long long numToBeAnded= (num&num-1) ^ num;
        // cout<<numToBeAnded<<endl;
        long long xor0=0;
        long long xor1=0;
        for(int i=0; i<size; i++){
            if(nums[i] & numToBeAnded){
                xor1^=nums[i];
            }
            else{
                xor0^=nums[i];
            }
        }

        vector<int> ans;
        ans.push_back(xor0);
        ans.push_back(xor1);
        return ans;

    }
};