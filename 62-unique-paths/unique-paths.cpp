class Solution {
public:
    int uniquePaths(int m, int n) {
        int r=min(m,n)-1;
        n=m+n-2;

        double ans=1;
        int i=1;
        
        while(i<=r){
            ans=ans*(n-r+i)/i;
            i++; 
        }
        return int(ans);
    }
};