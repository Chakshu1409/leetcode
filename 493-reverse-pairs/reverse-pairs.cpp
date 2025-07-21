class Solution {
public:

    void merge(vector<int>& nums, int start, int mid, int end){
        int i=start;
        int j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=end){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]); 
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }
        int it=0;
        for(int k=start; k<=end; k++){
            nums[k]=temp[it];
            it++;
        }
    }

    int countPairs(vector<int>& nums, int start, int mid, int end){
        int i=start;
        int j=mid+1;
        int ans=0;
        while(j<=end && i<=mid){
            while(i<=mid && nums[i] <= 2LL*nums[j]){
                i++;
            }
            ans+= (mid-i+1);
            j++;
        }
        return ans;
    }

    int mergeSort(vector<int>& nums, int start, int end){
        int size=nums.size();
        if(start >= end) return 0;

        int mid= start + (end - start)/2;
        int left= mergeSort(nums, start, mid);
        int right=mergeSort(nums, mid+1, end);
        int countMerge=countPairs(nums, start, mid, end);
        merge(nums, start, mid, end);
        cout<<left<<" "<<right<<" "<<countMerge<<endl;
        return left+right+countMerge;
    }

    int reversePairs(vector<int>& nums) {
        int size=nums.size();
        return mergeSort(nums,0,size-1);
    }
};