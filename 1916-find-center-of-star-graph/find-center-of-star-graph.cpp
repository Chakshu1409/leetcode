class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int one= edges[0][0];
        int two= edges[0][1];
        int three= edges[1][0];
        int four= edges[1][1];

        if(one==three || one==four){
            return one;
        }
        return two;
    }
};