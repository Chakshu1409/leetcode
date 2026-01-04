class Solution {
public:

    void buildIntervalDpForTellingPalindromeOfAndSubstringInAString(string s, vector<vector<bool>>& dp) {
        // for dp[i][j] you need dp[i+1][j-1].
        // if s[i] == s[j] then only there is a chance of making dp[i][j] = true.
        // base case of i=j and j-i=1 should be covered by yourself otherwise garbage values  aa jaygi.

        int size=s.size();

        for (int i=0; i<size; i++) {
            dp[i][i]=true;
        }
        for (int i=0; i<size-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1]=true;
            }
            else {
                dp[i][i+1]=false;
            }
        }

        for (int i=size-1; i>=0; i--) {
            for (int j=i+2; j<size; j++) {
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }
    }


    int minCut(string s) {
        int size=s.size();
        vector<vector<bool>> isPalindrome(size, vector<bool>(size, false));

        buildIntervalDpForTellingPalindromeOfAndSubstringInAString(s, isPalindrome);

        // dp[i] = minimum cuts needed for substring s[0…i]
        // goal is dp[size-1] as it will give minimum cuts needed for substring s[0...size-1]
        vector<int> dp(size, INT_MAX);
        dp[0]=0;

        for(int i=1; i<size; i++){
            if(isPalindrome[0][i]){
                dp[i]=0;
                continue;
            }
            // try all last cuts..
            for(int j=1; j<=i; j++){
                if(isPalindrome[j][i]){
                    dp[i] = min(dp[i], 1+dp[j-1]);
                }
            }
        }
        
        return dp[size-1];

    }
};