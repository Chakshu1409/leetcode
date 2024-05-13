class Solution {
public:
    int helper(vector<vector<int>> grid){
        int size=grid.size();
        for(int i=0; i<size; i++){
            if(grid[i][0]==0){
                for(int j=1; j<grid[0].size(); j++){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }
                    else{
                        grid[i][j]=0;
                    }
                }
            } 
        }

        int sum=size*pow(2,grid[0].size()-1);
        int x=1;
        for(int j=grid[0].size()-1; j>0; j--){
            int count1=0;
            int count2=0;
            for(int i=0; i<size; i++){
                if(grid[i][j]==0){
                    count1++;
                }
                else{
                    count2++;
                }
            }
            sum+=max(count1,count2) * x;
            x*=2;
        }
        return sum;
    }

    int matrixScore(vector<vector<int>>& grid) {
        int option1=helper(grid);
        int size=grid.size();
        for(int i=0; i<size; i++){
            if(grid[i][0]==0){
                grid[i][0]=1;
            }
            else{
                grid[i][0]=0;
            }
        }
        int option2=helper(grid);

        return max(option1,option2);
    }
};