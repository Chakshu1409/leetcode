class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size=nums.size();

        vector<int> ans(2*size, -1);
        stack<int> st;

        for(int i=2*size-1; i>=0; i--){
            while(!st.empty() && nums[i%size]>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(nums[i%size]);
        }
        vector<int> ansOrg;
        for(int i=0; i<size; i++){
            ansOrg.push_back(ans[i]);
        }

        return ansOrg;
    }
};