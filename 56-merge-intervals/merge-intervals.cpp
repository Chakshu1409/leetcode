class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int size=intervals.size();
        int i=0;
        int j=1;
        if(size==1){
            return intervals;
        }
        vector<vector<int>> ans;
        
        while(j<size){
            int start=intervals[i][0];
            int end=intervals[i][1];
            while(j<size){
                if(intervals[j][0] <= end){
                    end=max(intervals[j][1],end);
                    j++;
                }
                else{
                    break;
                }
            }
            vector<int> temp;
            temp.push_back(start);
            temp.push_back(end);

            ans.push_back(temp);
            i=j;
        }
        return ans;
    }
};