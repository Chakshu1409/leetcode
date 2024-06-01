class Solution {
public:
    int scoreOfString(string s) {
        int size=s.size();
        int ans=0;
        for(int i=1; i<size; i++){
            ans+= abs(s[i]-s[i-1]);
        }
        return ans;
    }
};