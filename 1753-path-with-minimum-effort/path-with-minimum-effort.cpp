class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int numRows=heights.size();
        int numCols=heights[0].size();

        vector<vector<int>> visited(numRows, vector<int>(numCols,1e9));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0,0,0});

        while(!q.empty()){
            int diff=q.top()[0];
            int rowIndex=q.top()[1];
            int colIndex=q.top()[2];

            q.pop();
            if(rowIndex==numRows-1 && colIndex==numCols-1){
                return diff;
            }

            vector<int> di={0,0,-1,1};
            vector<int> dj={1,-1,0,0};

            for(int i=0; i<4; i++){
                int nextRowInd=rowIndex+di[i];
                int nextColInd=colIndex+dj[i];

                if(nextRowInd>=0 && nextRowInd<numRows && nextColInd>=0 && nextColInd<numCols &&
                    max(diff,abs(heights[nextRowInd][nextColInd] - heights[rowIndex][colIndex])) < 
                    visited[nextRowInd][nextColInd]){
                        visited[nextRowInd][nextColInd]=max(diff,abs(heights[nextRowInd][nextColInd] - heights[rowIndex][colIndex]));
                        q.push({max(diff,abs(heights[nextRowInd][nextColInd] - heights[rowIndex][colIndex])), nextRowInd, nextColInd});
                    }
            }
        }
        return -1;
    }
};