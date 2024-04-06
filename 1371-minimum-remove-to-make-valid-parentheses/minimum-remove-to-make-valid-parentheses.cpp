class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int size=s.size();
        stack<char> st;
        string ans="";
        int count=0;
        for(int i=0; i<size; i++){
            if(s[i] == '('){
                ans+='(';
                count++;
            }
            else if(s[i] == ')'){
                if(count>0){
                    ans+=')';
                    count--;
                }
            }
            else{
                ans+=s[i];
            }
        }
        string finalAns="";
        int count2=0;
        for(int i=ans.size()-1; i>=0; i--){
            if(ans[i] == ')'){
                finalAns+=')';
                count2++;
            }
            else if(ans[i] == '('){
                if(count2>0){
                    count2--;
                    finalAns+='(';
                }
            }
            else{
                finalAns+=ans[i];
            }
        }
        reverse(finalAns.begin(), finalAns.end());

        return finalAns;
    }
};