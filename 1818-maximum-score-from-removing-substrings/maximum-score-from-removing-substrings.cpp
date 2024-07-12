class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int size=s.size();
        bool flag=false;
        if(x<y){
            flag=true;
            for(int i=0; i<size; i++){
                if(s[i] == 'a'){
                    s[i]='b';
                }
                else if(s[i] == 'b'){
                    s[i]='a';
                }
            }
        }
        int countA=0;
        int first=0;
        int second=0;

        vector<int> aIndex;
        vector<int> bIndex;

        for(int i=0; i<size; i++){
            
            if(s[i]=='a'){
                countA++;
                aIndex.push_back(i);
            }
            else if(s[i] == 'b'){
                if(countA > 0){
                    countA--;
                    first++;
                    bIndex.push_back(i);
                }
            }
            else{
                countA=0;
            }
        }

        int sizeB=bIndex.size();
        int sizeA=aIndex.size();

        int i=sizeA-1;
        int j=sizeB-1;

        unordered_map<int,int> mapIndex;

        while(j>=0){
            if(bIndex[j] > aIndex[i]){
                mapIndex[bIndex[j]]=1;
                mapIndex[aIndex[i]]=1;
                i--;
                j--;
            }
            else{
                i--;
            }
        }

        string newS;
        for(int i=0; i<size; i++){
            if(mapIndex[i] == 0){
                newS+=s[i];
            }
        }

        cout<<newS<<endl;
        // cout<<first*x;
        size=newS.size();
        int countB=0;
        for(int i=0; i<size; i++){
            
            if(newS[i]=='b'){
                countB++;
            }
            else if(newS[i] == 'a'){
                if(countB > 0){
                    countB--;
                    second++;
                }
            }
            else{
                countB=0;
            }
        }
        // cout<<second;
        if(flag){
            return x*second + y*first;
        }

        return x*first + y*second;



    }
};