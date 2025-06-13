class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1=word1.size();
        int size2=word2.size();

        vector<int> dp(size2+1, 0);
        for(int i=0; i<=size2; i++){
            dp[i]=i;
        }

        for(int i=0; i<size1; i++){
            vector<int> currDp(size2+1,0);
            for(int j=0; j<=size2; j++){
                if(j==0){
                    currDp[j]=i+1;
                    continue;
                }
                if(word1[i] == word2[j-1]){
                    currDp[j] = dp[j-1];
                }
                else{
                    currDp[j] = 1 + min(currDp[j-1],dp[j]);
                }
            }
            // for(int k=0; k<=size2; k++){
            //     cout<<currDp[k]<<" ";
            // }
            // cout<<endl;
            dp=currDp;
        }
        return dp[size2];
    }
};