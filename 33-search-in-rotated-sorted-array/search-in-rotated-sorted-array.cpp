class Solution {
public:
    int findPivot(vector<int>& nums){
        int size=nums.size();
        int si=0;
        int ei=size-1;

        while(si<ei){
            int mid= (si+ei)/2;

            if(nums[mid] >= nums[0]){
                si=mid+1;
            }
            else{
                ei=mid;
            }
        }
        return ei;
    }
    int binary(vector<int>& nums,int si, int ei, int target){

        while(si<=ei){
            int mid=(si+ei)/2;
            
            if(nums[mid] > target){
                ei=mid-1;
            }
            else if(nums[mid] < target){
                si=mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int size=nums.size();
        int index=findPivot(nums);
        cout<<index;
        int first=binary(nums,0,index-1,target);
        int second=binary(nums,index,size-1, target);

        if(first==-1 && second==-1){
            return -1;
        }
        if(first!=-1){
            return first;
        }
        return second;
    }
};