class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size=s.size();

        int i=0;
        int j=0;

        int ans=0;
        unordered_map<char,int> map;

        while(j<size){
            while(j<size && map[s[j]]==0){
                map[s[j]]++;
                j++;
            }
            ans=max(j-i, ans);
            if(j==size){
                break;
            }
            map[s[i]]--;
            i++;
        }
        return ans;
    }
};