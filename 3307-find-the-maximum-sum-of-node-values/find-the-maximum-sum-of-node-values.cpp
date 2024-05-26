class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // i can choose any pair of nodes and do there XOR.
        // the xor will traverse.
        // find the number of nodes which increase if it is XORed;
        // if there are odd number of nodes, which increase on XORING
           // then choose one element from elements which do not increase 
           // on xoring and pair the element with the element wich decreasews the lowest..
        
        // if odd number..
          // find the node with smallest incrase;
          // if nodes are present to pair with leave the process.
          // find the node with smallest decrease(if there are nodes present);
          // if decrease > increase  --> do nothing
          // else take xor of both of them..

        // the main catch is i can propogate XOR anywhere in the tree
        int n=nums.size();
        vector<int> diff(n,0);
        int count=0;
        int maxiNegative=INT_MIN;
        int miniPositive=INT_MAX;
        for(int i=0; i<n; i++){
            diff[i] = (nums[i]^k) - nums[i];
            if(diff[i] > 0){
                count++;
                miniPositive=min(diff[i], miniPositive);
            }
            if(diff[i] <= 0){
                maxiNegative= max(maxiNegative, diff[i]);
            }
        }
        cout<<count<<"kl";


        long long ans=0;
        if(maxiNegative == INT_MIN){
            for(int i=0; i<n; i++){
                ans  += nums[i] + diff[i];
            }
            if(n%2==0){
                return ans;

            }
            ans-=miniPositive;
            return ans;
        }

        if(count%2==0){
            // cout<<"HI";
            for(int i=0; i<n; i++){
                ans+= nums[i];
                if(diff[i] > 0){
                    ans += diff[i]; 
                }
            }
            return ans;
        }

        if(abs(maxiNegative) < miniPositive){
            //  cout<<"HI";
            for(int i=0; i<n; i++){
                ans+= nums[i];
                if(diff[i] > 0){
                    ans+= diff[i];
                }
            }
            ans+=maxiNegative;
            return ans;
        }

        for(int i=0; i<n; i++){
            ans+= nums[i];
            if(diff[i] > 0){
                ans+= diff[i];
            }        
        }
        ans-=miniPositive;
        return ans;


    }
};