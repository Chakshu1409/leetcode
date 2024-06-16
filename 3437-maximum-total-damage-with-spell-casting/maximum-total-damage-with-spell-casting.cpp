class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int size=power.size();
        unordered_map<long long, long long> map;
        for(int i=0; i<size; i++){
            map[power[i]]++;
        }

        vector<pair<long long,long long>> nums;
        for(auto it: map){
            nums.push_back(it);
        }

        sort(nums.begin(),nums.end());
        size=nums.size();
        vector<long long> dp(size,0);
        dp[0]=nums[0].first*nums[0].second;

        for(int i=1; i<size; i++){
            int j=i-1;
            cout<<nums[i].first<<endl;
            while(j>=0 && nums[i].first - nums[j].first <=2){
                dp[i]= max(dp[i],dp[j]);
                j--;
            }
            if(j<0){
                dp[i] = max(dp[i], nums[i].first*nums[i].second);
            }
            else{
                dp[i] = max(dp[i], dp[j]+nums[i].first*nums[i].second);
            }
        }
        return dp[size-1];
    }
};