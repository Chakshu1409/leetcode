class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        // for(auto it: ans){
        //         for(auto ij: it){
        //             cout<<ij<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        //     cout<<ans.back()[1]<<endl;
        //     cout<<endl;
        for(int i=1; i<size; i++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
            else{
                // cout<<i<<endl;
                ans.push_back(intervals[i]);
            }
            // for(auto it: ans){
            //     for(auto ij: it){
            //         cout<<ij<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
        }

        return ans;
    }
};