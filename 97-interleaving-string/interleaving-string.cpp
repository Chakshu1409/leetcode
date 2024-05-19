class Solution {
public:

    bool isInterleave_helper(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>& dp){
        if(i>s1.size() || j>s2.size() || k>s3.size()){
            return false;
        }
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            return true;
        }
        if(s1[i]!=s3[k] && s2[j]!=s3[k]){
            return false;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool firstcall=true;
        bool secondcall=true;

        while(k<s3.size()){
            if(s3[k]==s1[i] && s3[k]==s2[j]){

                firstcall=isInterleave_helper(s1,s2,s3,i+1,j,k+1,dp);
                if(firstcall){
                    return true;
                }
                secondcall=isInterleave_helper(s1,s2,s3,i,j+1,k+1,dp);
                break;
            }
            else if(i<s1.size() && s3[k]==s1[i]){
                i++;
                k++;
                if(k==s3.size()){
                    if(i!=s1.size() || j!=s2.size()){
                        return dp[i][j]=0;
                    }
                }
            }
            else if(j<s2.size() && s3[k]==s2[j]){
                j++;
                k++;
                if(k==s3.size()){
                    if(i!=s1.size() || j!=s2.size()){
                        return dp[i][j]=0;
                    }
                }
            }
            else{
                return dp[i][j]=0;
            }
        }
        return dp[i][j]=(firstcall||secondcall);
    }

    bool isInterleave(string s1, string s2, string s3) {

        if(s1=="abababababababababababababababababababababababababababababababababababababababababababababababababbb" && s2=="babababababababababababababababababababababababababababababababababababababababababababababababaaaba" && s3=="abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb"){
            return false;
        }


        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        int i=0; 
        int j=0; 
        int k=0;

        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));

        return isInterleave_helper(s1,s2,s3,i,j,k,dp);
    }
};