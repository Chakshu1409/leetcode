class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size=nums.size();
        vector<int> ans(2*size,-1);

        stack<int> st;
        for(int i=2*size-2; i>=0; i--){
            while(!st.empty() && nums[i%size] >= st.top()){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(nums[i%size]);
        }

        vector<int> anss(size, 0);
        for(int i=0; i<size; i++){
            anss[i]=ans[i];
        }

        return anss;
    }
};