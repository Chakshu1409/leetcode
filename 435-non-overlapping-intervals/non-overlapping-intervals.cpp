class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size=intervals.size();
        sort(intervals.begin(), intervals.end());

        int toBeAdded=0;

        int i=0;
        int j=0;

        while(j<size){
            toBeAdded++;
            int currentEnd=intervals[i][1];
            while(j<size){
                if(intervals[j][0] >= currentEnd){
                    break;
                }
                else{
                    currentEnd=min(currentEnd, intervals[j][1]);
                    j++;
                }
            }
            i=j;
        }
        return size-toBeAdded;
    }
};