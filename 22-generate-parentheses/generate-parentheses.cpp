class Solution {
public:
    void recurr(int n, vector<string>& ans, string& ds, int& open, int& close){
        if(n==0){
            if(open == close){
                ans.push_back(ds);
            }
            return;
        }

        if(open >= close){
            ds=ds+"(";
            open++;
            n--;
            recurr(n, ans, ds, open, close);
            ds.pop_back();
            open--;
            n++;
        }

        if(close < open){
            ds=ds+")";
            close++;
            n--;
            recurr(n,ans, ds, open, close);
            ds.pop_back();
            close--;
            n++;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds="";
        int countOpen=0;
        int countClose=0;
        recurr(2*n, ans, ds, countOpen, countClose);

        return ans;
    }
};