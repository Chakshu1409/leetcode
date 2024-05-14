class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjency(n,vector<int>(n,1e9));
        int size=edges.size();

        for(int i=0; i<size; i++){
            adjency[edges[i][0]][edges[i][1]]= edges[i][2];
            adjency[edges[i][1]][edges[i][0]]= edges[i][2];
        }
        for(int i=0; i<n; i++){
            adjency[i][i]=0;
        }

       for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					adjency[i][j] = min(adjency[i][j],
					                   adjency[i][k] + adjency[k][j]);
				}
			}
		}
        int finalcount=n;
        int ans=-1;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(adjency[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(finalcount>=count){
                finalcount=count;
                ans=i;
            }
        }
        return ans;
    }
};