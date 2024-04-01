class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length();
        int x,y;
        for(int i = size-1;i>=0;i--){
            if(s[i] != ' '){
                x=i;
                break;                    
            }
        }
        for(int j=x;j>=0;j--){
            if(s[j] == ' '){
                y=j;
                break;
            }
                
        }
        return (x-y);
    }
};