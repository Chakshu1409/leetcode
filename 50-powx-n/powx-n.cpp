class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        double ans=1.0;
        if(nn<0){
            nn=(0-nn);
        }
        while(nn){
            if(nn%2){
                nn--;
                ans=ans*x;
            }
            else{
                x=x*x;
                nn/=2;
            }
        }
        if(n<0){
            ans = (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};