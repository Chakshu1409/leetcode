class Solution {
public:
    int numSteps(string s) {
        int size=s.size();
        int i=size-1;
        int ans=0;
        int carry=0;
        while(i>0){
            if(s[i] == '0'){
                if(carry==1){
                    ans+=2;
                    
                }
                else{
                    ans+=1;
                }
            }
            else{
                if(carry==1){
                    ans+=1;
                }
                else{
                    ans+=2;
                    carry=1;
                }
            }
            i--;
        }
        if(carry==1){
            ans++;
        }
        return ans;
    }
};