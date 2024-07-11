class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();

        vector<int> jumpIndex(n,0);

        stack<int> st;
        int count=0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int top= st.top();
                st.pop();
                jumpIndex[i]=top;
                jumpIndex[top]=i;
            }
            else{
                count++;
            }
        }

        bool right=false;
        int i=0;
        string ans="";
        while(i<n && s[i]!='('){
            ans+=s[i];
            i++;
        }
        
        while(i>=0 && i<n && ans.size() < count){
            if(!right){
                cout<<i<<endl;
                i=jumpIndex[i];
                cout<<i<<endl<<endl;
                i--;
                while( i>=0 && (s[i] != '(' && s[i] != ')') && ans.size() < count){
                    ans+=s[i];
                    i--;
                }
                right=true;
            }
            else{
                cout<<i<<endl;
                i=jumpIndex[i];
                cout<<i<<endl<<endl;
                i++;
                while( i<n && (s[i] != '(' && s[i] != ')') && ans.size() < count){
                    ans+=s[i];
                    i++;
                }
                right = false;
            }
        }

        return ans;
    }
};