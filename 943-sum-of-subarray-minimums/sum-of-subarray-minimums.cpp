class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int size=arr.size();

        stack<int> st;

        vector<int> prevSmallerInd(size,-1);

        for(int i=0; i<size; i++){
            // return 0;
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            // return 0;
            // cout<<"HI";
            if(st.empty()){
                st.push(i);
                prevSmallerInd[i]=-1;
                continue;
            }
            prevSmallerInd[i]=st.top();
            st.push(i);
        }
        // return 0;
        vector<int> dp(size,0);
        int ans=0;
        for(int i=0; i<size; i++){
            if(prevSmallerInd[i] == -1){
                dp[i] = (i+1)*arr[i];
            }
            else{
                dp[i] = dp[prevSmallerInd[i]] + (i-prevSmallerInd[i])*arr[i];
            }
        }

        for(int i=0; i<size; i++){
            ans = (ans + dp[i])%1000000007;
        }

        return ans;

    }
};