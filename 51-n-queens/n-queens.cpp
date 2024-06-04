class Solution {
public:
    void helper(int n, int si, vector<vector<string>>& ans, vector<string>& temp, string pushed){
        if(si==n){
            ans.push_back(temp);
            return;
        }
        
        for(int j=0; j<n; j++){
            bool flag=true;
            for(int i=0; i<si; i++){
                if(temp[i][j] == 'Q'){
                    flag=false;
                }
            }
            int tempJ=j+1;
            for(int i=si-1; i>=0&&tempJ<n; i--){
                if(temp[i][tempJ] == 'Q'){
                    flag=false;
                }
                tempJ++;
            }

            tempJ=j-1;
            for(int i=si-1; i>=0 && tempJ>=0; i--){
                if(temp[i][tempJ] == 'Q'){
                    flag=false;
                }
                tempJ--;
            }

            if(flag){
                pushed[j]='Q';                
                temp.push_back(pushed);
                pushed[j]='.';
                helper(n,si+1,ans,temp,pushed);
                temp.pop_back();
            }

        }
    }

    vector<vector<string>> solveNQueens(int n) {
        int i=0;
        vector<vector<string>> ans;
        vector<string> temp;
        string pushed="";
        for(int i=0; i<n; i++){
            pushed+='.';            
        }
        helper(n,i,ans,temp,pushed);
        return ans;
    }
};