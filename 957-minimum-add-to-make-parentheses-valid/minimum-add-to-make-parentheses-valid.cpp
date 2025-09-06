class Solution {
public:
    int minAddToMakeValid(string s) {
        int size=s.size();

        stack<char> st;
        int ans=0;

        for(int i=0; i<size; i++){
            if(s[i] == '('){
                st.push('(');
            }

            else{
                if(st.empty()){
                    ans++;
                    continue;
                }
                else{
                    st.pop();
                }
            }
        }
        ans+=st.size();
        return ans;
    }
};