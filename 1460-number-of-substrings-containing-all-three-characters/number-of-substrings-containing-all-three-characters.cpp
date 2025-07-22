class Solution {
public:
    int numberOfSubstrings(string s) {
        int size=s.size();

        int ans=0;
        int i=0;
        int j=0;

        vector<int> freq(3,0);

        while(j<size){
            while(j<size){
                freq[s[j]-'a']++;
                bool allPresent=freq[0]&&freq[1]&&freq[2];
                if(allPresent){
                    ans+=(size-j);
                    j++;
                    break;
                }
                j++;
            }
            // cout<<ans<<endl;
            while(i<=j){
                freq[s[i]-'a']--;
                bool allPresent=freq[0]&&freq[1]&&freq[2];
                if(!allPresent){
                    i++;
                    break;
                }
                ans+=(size-j+1);
                i++;
            }
            // cout<<ans<<endl;
            // j++;
        }
        return ans;
    }
};