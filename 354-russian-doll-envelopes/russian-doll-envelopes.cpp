class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort by width ascending, and by height descending when widths are equal
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        // Extract the heights
        vector<int> dp;
        for (const auto& env : envelopes) {
            int height = env[1];
            auto it = lower_bound(dp.begin(), dp.end(), height);
            if (it == dp.end()) {
                dp.push_back(height);
            } else {
                *it = height;
            }
        }
        return dp.size();
    }
};
