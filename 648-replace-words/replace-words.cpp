class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> map;
        int sizeD=dictionary.size();
        for(int i=0; i<sizeD; i++){
            map[dictionary[i]]=1;
        }
        int size=sentence.size();
        string ans="";

        int i=0; 
        while(i<size){
            string temp="";
            bool flag=false;
            while(i<size && sentence[i]!=' '){
                temp+=sentence[i];
                i++;
                if(map[temp]){
                    ans+=temp+" ";
                    flag=true;
                    break;
                }
            }
            if(!flag){
                ans+=temp+" ";
            }
            while(i<size && sentence[i]!=' '){
                i++;
            }
            i++;
        }
        
        int ansSize=ans.size();
        return ans.substr(0,ansSize-1);
    }
};