class Solution {
public:
    // we have to make a 2-D prefix maxtrix which stores the number
    // of x's and number of y's in the submatrix till that block
    // starting from (0,0);

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        vector<vector< pair<int,int> >> freq(n, vector<pair<int,int>>(m,{0,0}));
        int ans=0;

        int numX=0;
        int numY=0;
        for(int i=0; i<n; i++){
            if(grid[i][0] == 'X'){
                numX++;
            }
            if(grid[i][0] == 'Y'){
                numY++;
            }

            freq[i][0]={numX,numY};
            if(numX == numY && numX!=0){
                ans++;
            }
        }

        numX=0;
        numY=0;
        for(int i=0; i<m; i++){
            if(grid[0][i] == 'X'){
                numX++;
            }
            if(grid[0][i] == 'Y'){
                numY++;
            }

            freq[0][i]={numX,numY};
            if(numX == numY && numX!=0){
                ans++;
            }
        }
        // cout<<ans<<endl;
       
        for(int i=1; i<n; i++){
            int numX=0;
            int numY=0;

            if(grid[i][0] == 'X'){
                numX++;
            }
            if(grid[i][0] == 'Y'){
                numY++;
            }

            for(int j=1; j<m; j++){
                if(grid[i][j] == 'X'){
                    numX++;
                }
                if(grid[i][j] == 'Y'){
                    numY++;
                }

                freq[i][j].first = freq[i-1][j].first + numX;
                freq[i][j].second = freq[i-1][j].second + numY;

                if(freq[i][j].first == freq[i][j].second && freq[i][j].first!=0){
                    ans++;
                }
            }
        }

        return ans;
    }
};