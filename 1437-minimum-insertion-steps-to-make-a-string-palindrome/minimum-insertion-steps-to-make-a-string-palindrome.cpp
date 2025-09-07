class Solution {
public:

    int recurr(string& orgS, string& revS, int size, int ind1, int ind2, vector<vector<int>>& dp){

        if(ind1 < 0){
            return ind2+1;
        }
        if(ind2 < 0){
            return ind1+1;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }


        if(orgS[ind1] == revS[ind2]){
            return recurr(orgS, revS, size, ind1-1, ind2-1, dp);
        }

        int first= 1 + recurr(orgS, revS, size, ind1-1, ind2, dp);
        int second = 1 + recurr(orgS, revS, size, ind1, ind2-1, dp);

        return dp[ind1][ind2]=min(first, second);

    }

    int minInsertions(string s) {
        int size=s.size();
        string orgS=s;
        string revS=s;

        int i=0;
        int j=size-1;

        while(i<=j){
            revS[i]=orgS[j];
            revS[j]=orgS[i];
            i++;
            j--;
        }
        vector<vector<int>> dp(size, vector<int>(size, -1));
        int numEqual = recurr(orgS, revS, size, size-1, size-1, dp);

        return numEqual/2;
        
    }
};