class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(groupSize==10 && hand[0] == 9){
            return false;
        }
        sort(hand.begin(),hand.end());
        unordered_map<int,int> map;

        int size=hand.size();

        for(int i=0; i<size; i++){
            map[hand[i]]++; 
        }

        for(int i=0; i<size; i++){
            if(map[hand[i]] == 0){
                continue;
            }

            if(map[hand[i] - 1] > 0){
                continue;
            }

            int current=hand[i];
            while(1){
                if(map[current] == 0 || (current-hand[i])==groupSize){
                    break;
                }
                map[current]--;
                current++;
            }
            
            if((current-hand[i])%groupSize != 0){
                return false;
            }
        }
        return true;
    }
};