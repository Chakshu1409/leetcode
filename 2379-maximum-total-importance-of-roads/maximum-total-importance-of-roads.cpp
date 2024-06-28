class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;

        vector<long long> numRoads(n,0);

        int size=roads.size();

        for(int i=0; i<size; i++){
            numRoads[roads[i][0]]++;
            numRoads[roads[i][1]]++;
        }

        sort(numRoads.begin(),numRoads.end());
        int current=n;

        for(int i=n-1; i>=0; i--){
            ans+=numRoads[i]*current;
            current--;
        }
        return ans;
    }
};