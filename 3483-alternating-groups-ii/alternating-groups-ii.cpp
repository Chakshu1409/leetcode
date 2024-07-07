class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int size=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        while(i<size){
            bool equal=true;
            if((j-i)%2 == 1){
                equal=false;
            }
            while(j-i<k){
                if(equal){
                    if(nums[j%size] == nums[i]){
                        j++;
                        equal =false;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(nums[j%size] != nums[i] ){
                        j++;
                        equal = true;
                    }
                    else{
                        break;
                    }
                }
            }

            if(j-i == k){
                ans++;
                i++;
            }
            else{
                i=j;
            }

        }
        return ans;
    }
};