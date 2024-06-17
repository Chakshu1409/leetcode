class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int,int> map;
        long long num=0;

        while(pow(num,2) <= c){
            if(map[c-pow(num,2)] == 1 || 2*pow(num,2) == c){
                return true;
            }
            map[pow(num,2)]++;
            num++;
        }
        return false;
    }
};