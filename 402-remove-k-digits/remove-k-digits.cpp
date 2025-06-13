class Solution {
public:
    string removeKdigits(string num, int k) {
        int size=num.size();

        if(k>=size){
            return "0";
        }

        stack<int> st;

        for(int i=0; i<size; i++){
            while(!st.empty() && st.top() > num[i]-'0' && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=(to_string(st.top()));
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        // cout<<ans<<endl;
        int index=-1;
        int size1=ans.size();
        for(int i=0; i<size1; i++){
            if(ans[i]!='0'){
                index=i;
                break;
            }
        }
        if(index == -1){
            return "0";
        }
        return ans.substr(index);
    }
};