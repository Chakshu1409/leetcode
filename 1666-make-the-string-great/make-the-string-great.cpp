class Solution {
public:
    string makeGood(string s) {
        int size=s.size();
        stack<char> st;
        if(size==0){
            return "";
        }
        st.push(s[0]);
        for(int i=1; i<size; i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(abs(s[i] - st.top()) == 32){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};