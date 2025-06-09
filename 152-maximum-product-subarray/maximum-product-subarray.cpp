class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int answer=INT_MIN;
        int n=nums.size();
	int maxiProduct=1;
	int minProduct=1;

	for(int i=0; i<n; i++){
    int temp= max(nums[i], max(maxiProduct*nums[i], minProduct*nums[i]));
	

	minProduct = min(nums[i], min(maxiProduct*nums[i], minProduct*nums[i]));

    maxiProduct=temp;
	
	answer = max(answer, maxiProduct);
    cout<<answer<<endl;
    cout<<maxiProduct<<endl;
    cout<<minProduct<<endl;
    cout<<endl;
}

return answer;

    }
};