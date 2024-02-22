class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int trustSize=trust.size();
        for(int i=1; i<=n; i++){
            int count=0;
            bool flag=true;
            for(int j=0; j<trustSize; j++){
                if(trust[j][1] == i){
                    count++;
                }
                if(trust[j][0] == i){
                    flag=false;
                    break;
                }
            }
            if(flag && count == n-1){
                return i;
            }
        }

        return -1;
    }
};