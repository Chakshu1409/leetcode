class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(), s.end());

        int gSize=g.size();
        int sSize=s.size();

        int i=0;
        int j=0;

        while(i<gSize && j<sSize){
            while(j<sSize && s[j] < g[i]){
                j++;
            }
            if(j==sSize){
                break;
            }
            i++;
            j++;
        }
        return i;
    }
};