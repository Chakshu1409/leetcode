class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;

        int numEmpty= numBottles;

        while(numEmpty >= numExchange){
            ans+= numEmpty/numExchange;

            numEmpty= (numEmpty%numExchange) + numEmpty/numExchange;

        }

        return ans;



    }
};