class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=s.size();
        int ans=0;
        int i=0; 
        int j=0; 
        unordered_map<char,int> map;
        while(j<size){
            while(j<size && map[s[j]] == 0){
                map[s[j]]++;
                j++;
                ans= max(ans, j-i);
            }
            if(j==size){
                break;
            }
            while(j<i && s[i] != s[j]){
                map[s[i]]--;
                i++;
            }
            map[s[i]]=0;
            i++;
        }
        return ans;

        // return ans;
    }
};