class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int size=nums.size();

        stack<int> st;

        vector<int> ans(2*size, -1);

        for(int i=((2*size)-1); i>=0; i--){

            if(st.empty() || nums[i%size] < st.top()){
                if(st.empty()){
                    ans[i] = -1;
                }
                else{
                    ans[i] = st.top();
                }
                st.push(nums[i%size]);
            }
            
            else{       // nums[i%size] >= st.top()

                while(!st.empty() && nums[i%size] >= st.top()){
                    st.pop();
                }

                if(st.empty()){
                    ans[i] = -1;
                }
                else{
                    ans[i] = st.top();
                }

                st.push(nums[i%size]);
            }
        }

        vector<int> finalAns;
        // for(int i=0; i<2*size; i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0; i<size; i++){
            finalAns.push_back(ans[i]);
        }

        return finalAns;


    }
};