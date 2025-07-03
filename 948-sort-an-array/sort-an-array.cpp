class Solution {
public:

    int partition(vector<int>& nums, int low, int high){
        int pivot=nums[low];
        int i=low;
        int j=high;

        while(i<j){
            while(i<=high-1 && nums[i] <= pivot){
                i++;
            }

            while(j>=low+1 && nums[j] > pivot){
                j--;
            }

            if(i<j){
                swap(nums[i],nums[j]);
            }
        }

        swap(nums[j],nums[low]);
        return j;
    }


    void quicksort(vector<int>& nums, int low, int high){
        if(low >= high){
            return;
        }
        int partitionIndex= partition(nums,low,high);

        quicksort(nums, low, partitionIndex-1);
        quicksort(nums, partitionIndex+1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();

        quicksort(nums,0,size-1);
        return nums;
    }
};