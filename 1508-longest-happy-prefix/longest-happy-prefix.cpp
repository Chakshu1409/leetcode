class Solution {
public:
    string longestPrefix(string s) {
        int pre=0, suf=1;
        int n=s.size();
        vector<int> lps(n,0);

        while(suf < n){
            if(s[pre] == s[suf]){
                lps[suf] = pre+1;
                pre++, suf++;
            }

            else{
                if(pre == 0) suf++;
                else pre = lps[pre-1];
            }
        }

        return s.substr(0,lps.back());
    }
};