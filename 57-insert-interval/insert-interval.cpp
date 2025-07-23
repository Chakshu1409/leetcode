class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size=intervals.size();
        sort(intervals.begin(), intervals.end());;;;;

        int i=0;
        int j=0;
        vector<vector<int>> ans;
        while(j<size){
            ans.push_back(intervals[i]);
            while(j<size){
                if(ans.back()[1] >= intervals[j][0]){
                    ans.back()[1]=max(ans.back()[1], intervals[j][1]);
                    j++;
                }
                else{
                    break;
                }
                i=j;
            }
        }
        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};