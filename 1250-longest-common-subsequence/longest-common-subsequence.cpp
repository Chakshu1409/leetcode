class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1=text1.size();
        int size2=text2.size();

        vector<int> dp(size2+1,0);

        for(int i=0; i<size1; i++){
            vector<int> tempDp(size2+1,0);
            for(int j=1; j<=size2; j++){
                if(text1[i] == text2[j-1]){
                    tempDp[j] = 1 + dp[j-1];
                }
                else{
                    tempDp[j] = max(dp[j],tempDp[j-1]);
                }
            }
            
            dp=tempDp;
        }
        return dp[size2];
    }
};