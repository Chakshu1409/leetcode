class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int size=bills.size();

        vector<int> count({0,0,0});
        for(int i=0; i<size; i++){
            if(bills[i] == 5){
                count[0]++;
            }
            else if(bills[i] == 10){
                if(count[0] == 0){
                    return false;
                }
                count[0]--;
                count[1]++;
            }
            else{
                if(count[0] == 0){
                    return false;
                }
                if(count[1] == 0 && count[0] < 3){
                    return false;
                }
                if(count[1] == 0){
                    count[0]-=3;
                }
                else{
                    count[0]-=1;
                    count[1]-=1;
                }
            }
        }
        return true;
    }
};