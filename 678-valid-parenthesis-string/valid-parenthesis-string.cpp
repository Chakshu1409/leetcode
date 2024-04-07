// Recursion --> 3^n
// Dynamic programming --> n^2 , n^2
// 2 stack approach -->  direct buffer lerkr answer wrong aayga, you have
// to store indexes of the opening in another stack and indexes of asterirsks
// in the another stack..
// class Solution {
// public:
//     bool checkValidString(string s) {
//         int size=s.size();
//         stack<int> stOpen;
//         stack<int> stAstersisk;

//         for(int i=0; i<size; i++){
//             if(s[i]=='('){
//                 stOpen.push(i);
//             }
//             else if(s[i]=='*'){
//                 stAstersisk.push(i);
//             }
//             else{
//                 if(!stOpen.empty()){
//                     stOpen.pop();
//                 }
//                 else if(!stAstersisk.empty()){
//                     stAstersisk.pop();
//                 }
//                 else{
//                     return false;
//                 }
//             }
//         }
//         while(!stOpen.empty()){
//             if(stAstersisk.empty()){
//                 return false;
//             }
//             if(stAstersisk.top()>stOpen.top()){
//                 stAstersisk.pop();
//                 stOpen.pop();
//             }
//             else{
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool helper(string s, int size, int index, int countOpen, vector<vector<int> >& dp){
        if(index==size){
            return countOpen==0;
        }

        if(dp[index][countOpen] != -1){
            return dp[index][countOpen];
        }

        if(s[index]=='*'){
            bool one=false;
            bool two=false;
            bool three=false;

            one=helper(s,size, index+1,countOpen+1,dp);
            two=helper(s,size, index+1,countOpen,dp);
            if(countOpen>0){
                three=helper(s,size, index+1, countOpen-1,dp);
            }
            return dp[index][countOpen]=one || two || three;
        }
        else if(s[index]=='('){
            return dp[index][countOpen]=helper(s,size, index+1, countOpen+1,dp);
        }
        else{
            if(countOpen>0){
                return dp[index][countOpen]=helper(s,size,index+1,countOpen-1,dp);
            }
            return dp[index][countOpen]=false;
        }
    }

    bool checkValidString(string s) {
        int size=s.size();

        int index=0;
        int countOpen=0;
        vector<vector<int> > dp(size,vector<int>(size,-1));
        return helper(s,size,index,countOpen,dp);

    }
};