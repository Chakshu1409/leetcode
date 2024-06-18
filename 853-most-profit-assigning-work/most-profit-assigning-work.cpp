class Solution {
public:

    int binary(vector<int>& worker, int num){
        int si=0;
        int ei=worker.size()-1;
        int ans=-1;
        while(si<=ei){
            int mid=si+ (ei-si)/2;

            if(worker[mid] >= num){
                ans=mid;
                ei=mid-1;
            }
            else{
                si= mid+1;
            }
        }

        return ans;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();

        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({profit[i],difficulty[i]});
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(), vec.end());

        // for(auto it: vec){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        sort(worker.begin(),worker.end());

        int i=0;
        int j=0;    
        int ans=0;

        while(i<n && j<m){
            int index=binary(worker,vec[i].second);
            if(index==-1){
                i++;
                continue;
            }
            
            ans+= vec[i].first;
            // cout<<index<<" "<<vec[index].first<<endl;
            worker.erase(worker.begin()+index);
            j++;
            // cout<<ans<<endl;
        }
        return ans;
    }
};