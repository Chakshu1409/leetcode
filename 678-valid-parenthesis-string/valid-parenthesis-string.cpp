// Recursion --> 3^n
// Dynamic programming --> n^2 , n^2
// 2 stack approach -->  direct buffer lerkr answer wrong aayga, you have
// to store indexes of the opening in another stack and indexes of asterirsks
// in the another stack..
class Solution {
public:
    bool checkValidString(string s) {
        int size=s.size();
        stack<int> stOpen;
        stack<int> stAstersisk;

        for(int i=0; i<size; i++){
            if(s[i]=='('){
                stOpen.push(i);
            }
            else if(s[i]=='*'){
                stAstersisk.push(i);
            }
            else{
                if(!stOpen.empty()){
                    stOpen.pop();
                }
                else if(!stAstersisk.empty()){
                    stAstersisk.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!stOpen.empty()){
            if(stAstersisk.empty()){
                return false;
            }
            if(stAstersisk.top()>stOpen.top()){
                stAstersisk.pop();
                stOpen.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};