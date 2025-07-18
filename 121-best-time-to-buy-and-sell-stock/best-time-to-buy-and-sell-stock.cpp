class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int ans=0;
        int size=prices.size();

        for(int i=1; i<size; i++){
            ans = max(ans, prices[i]-mini);
            mini=min(mini, prices[i]);
        }
        return ans;
    }
};