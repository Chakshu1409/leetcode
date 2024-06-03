class Solution {
public:
    int appendCharacters(string s, string t) {
        int sizeS=s.size();
        int sizeT=t.size();

        int i=0;
        int j=0;

        while(i<sizeS && j<sizeT){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return sizeT-j;
    }
};