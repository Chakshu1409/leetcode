class Solution {
public:
    int characterReplacement(string s, int m) {
        int size=s.size();
        vector<int> freq(26,0);

        int i=0;
        int j=0;
        int ans=0;

        while(j<size){
            while(j<size){
                freq[s[j]-'A']++;
                int maxi=INT_MIN;
                for(int k=0; k<26; k++){
                    maxi=max(maxi, freq[k]);
                }
                int numToReplace=(j-i-maxi+1);
                if(numToReplace > m){
                    // freq[s[j]-'A']--;
                    break;
                }
                ans=max(ans, j-i+1);
                j++;
            }
            if(j==size){
                return ans;
            }
            while(i<=j){
                freq[s[i]-'A']--;
                int maxi=INT_MIN;
                for(int k=0; k<26; k++){
                    maxi=max(maxi, freq[k]);
                }
                i++;
                int numToReplace=(j-i+1-maxi);
                if(numToReplace <= m){
                    break;
                }
            }
            j++;
        }
        return ans;
    }
};