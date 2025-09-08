class Solution {
public:

    class DSU{
        public: 

        vector<int> par;
        vector<int> rank;

        DSU(int n){
            par.resize(n);
            rank.resize(n,0);

            for(int i=0; i<n; i++){
                par[i]=i;
            }
        }

        int findUPar(int node){
            if(par[node] == node){
                return node;
            }
            return par[node]=findUPar(par[node]);
        }

        void unionByRank(int u, int v){
            int ultParU = findUPar(u);
            int ultParV = findUPar(v);

            if(ultParU == ultParV){
                return;
            }
            if(rank[ultParU] > rank[ultParV]){
                par[ultParV]=ultParU;
            }
            else if(rank[ultParU] < rank[ultParV]){
                par[ultParU]=ultParV;
            }
            else{
                par[ultParU]=ultParV;
                rank[ultParV]++;
            }
        }

    };

    int removeStones(vector<vector<int>>& stones) {
        int totalStones = stones.size();
        DSU dsu(totalStones);

        for(int i=0; i<totalStones; i++){
            for(int j=i+1; j<totalStones; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    dsu.unionByRank(i,j);
                }
            }
        }

        int numGroups=0;
        for(int i=0; i<totalStones; i++){
            if(dsu.findUPar(i) == i){
                numGroups++;
            }
        }

        return totalStones-numGroups;
    }
};