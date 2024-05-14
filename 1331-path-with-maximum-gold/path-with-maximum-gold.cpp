class Solution {
public:
    void helper(vector<vector<int>>& grid, vector<vector<int>>& grid1,int numrow, int numcol,int si, int sj, int& current, int& ans){
        if(si<0 || si>=numrow || sj<0 || sj>=numcol || grid1[si][sj]==0){
            ans=max(ans,current);
            return ;
        }

        current+=grid1[si][sj];
        grid1[si][sj]=0;

        helper(grid,grid1,numrow,numcol,si+1,sj,current,ans);
        helper(grid,grid1,numrow,numcol,si-1,sj,current,ans);
        helper(grid,grid1,numrow,numcol,si,sj+1,current,ans);
        helper(grid,grid1,numrow,numcol,si,sj-1,current,ans);

        grid1[si][sj]=grid[si][sj];
        current-=grid[si][sj];

    }

    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> grid1=grid;
        int numrow=grid.size();
        int numcol=grid[0].size();
        int current=0;
        int finalAns=0;

        for(int i=0; i<numrow; i++){
            for(int j=0; j<numcol; j++){
                int ans=0; 
                helper(grid,grid1,numrow,numcol,i,j,current,ans);
                finalAns=max(ans, finalAns);
            }
        }

        return finalAns;
    }
};