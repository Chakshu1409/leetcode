class Solution {
public:
    int recur(string& s, int size, vector<vector<int>>& dp, int index, int num){

        if(index==size && num==0){
            return 1;
        }
        if(num<0){
            return 0;
        }
        if(index==size){
            return 0;
        }

        if(dp[index][num] != -1){
            return dp[index][num];
        }
        int ans=0;
        if(s[index] == '*'){
            ans = ans || recur(s,size,dp,index+1,num);
            ans = ans || recur(s,size,dp,index+1,num+1);
            ans = ans || recur(s,size,dp,index+1,num-1);
        }
        else if(s[index] == '('){
            ans=recur(s,size,dp,index+1,num+1);
        }
        else{
           ans=recur(s,size,dp,index+1,num-1);
        }
        return dp[index][num] = ans;
    }

    bool checkValidString(string s) {
        int size=s.size();
        vector<vector<int>> dp(size+1, vector<int>(size+1, -1));

        if(recur(s,size,dp,0,0)){
            return true;
        }
        return false;
    }
};