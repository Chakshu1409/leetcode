class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>>pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        pq.push({nums[0],0});
        p.push({nums[0],0});
         int i=0;
         int j=1;
         int count=1;
        while(j<nums.size()){
            while(pq.size()&&pq.top().second<i) pq.pop();
            while(p.size()&&p.top().second<i) p.pop();
         int minE = p.top().first;
         int maxE = pq.top().first;
         if(maxE-minE<=limit){
             count = max(count,j-i);
             pq.push({nums[j],j});
             p.push({nums[j],j});
             j++;
         }
         else{
           i++;
         }
        }
         int minE = p.top().first;
         int maxE = pq.top().first;
         if(maxE-minE<=limit){
             count = max(count,j-i);
         }
        return count;
    }
};