class Solution {
public:
    bool checkRecord(string s) {
        int size=s.size();
        int count1=0;
        int count2=0;
        for(int i=0; i<size; i++){
            if(s[i]=='A'){
                count1++;
                count2=0;
            }
            else if(s[i]=='L'){
                count2++;
            }
            else{
                count2=0;
            }
            if(count1>1 || count2>=3){
                return false;
            }
        }
        return true;
    }
};