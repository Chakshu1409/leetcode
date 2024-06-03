class Solution {
public:
    void helper(string& s, int& size, int index, vector<vector<string>>& ans, vector<string> temp, vector<vector<int>>& check){
        if(index==size){
            ans.push_back(temp);
            return;
        }
        string current="";
        for(int i=index; i<size; i++){
            current+=s[i];
            if(check[index][i] == 1){
                temp.push_back(current);
                helper(s,size,i+1,ans,temp,check);
                temp.pop_back();
            }
        }
    }

    bool checkPalind(string s){
        int size=s.size();
        for(int i=0; i<size/2; i++){
            if(s[i] != s[size-1-i]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        int size=s.size();
        int index=0;

        vector<vector<int>> check(size, vector<int>(size,0));
        for(int i=0; i<size; i++){
            string current="";
            for(int j=i; j<size; j++){
                current+=s[j];
                if(checkPalind(current)){
                    check[i][j]=1;
                }
            }
        }

        vector<string> temp;
        vector<vector<string>> ans;
        helper(s,size,index,ans,temp,check);

        return ans;

    }
};