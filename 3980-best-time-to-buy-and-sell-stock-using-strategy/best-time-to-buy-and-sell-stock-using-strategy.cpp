class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
      int size=prices.size();
      long long ans=0;

      int i,j;
      i=0;
      j=k-1;

      long long current=0;
      for(int i=0; i<size; i++){
        ans+=(prices[i]*strategy[i]*1LL);
      }

      for(int i=0; i<size; i++){
        if(i < k/2){
          current+=0;
        }
        else if(i<k && i>=k/2){
          current+=prices[i]*1LL;
        }
        else{
          current+=prices[i]*strategy[i]*1LL;
        }
      }
      // cout<<current<<endl;
      // return 0;
      // cout<<current<<endl;
      while(j<size){
        if(ans<current){
          ans=current;
        }
        if(j==size-1){
          break;
        }
        current+=(prices[i]*strategy[i]*1LL);
        current-=(prices[i+(k/2)])*1LL;
        current-=(prices[j+1]*strategy[j+1]*1LL);
        current+=(prices[j+1])*1LL;
        i++;
        j++;
      }
      return ans*1LL;
    }
};