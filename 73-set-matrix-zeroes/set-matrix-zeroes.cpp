class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int colZero=1;
        int rowZero=1;

        for(int i=0; i<n; i++){
            if(matrix[i][0] == 0){
                colZero=0;
            }
        }
        for(int i=0; i<m; i++){
            if(matrix[0][i] == 0){
                rowZero=0;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j]=0;
                } 
            }
        }
        if(rowZero==0){
            for(int i=0; i<m; i++){
                matrix[0][i]=0;
            }
        }
        if(colZero==0){
            for(int i=0; i<n; i++){
                matrix[i][0]=0;
            }
        }
        return;
    }
};