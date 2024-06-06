class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size=hand.size();
        if(size%groupSize != 0){
            return false;
        }

        map<int,int> mapp;
        for(int i=0; i<size; i++){
            mapp[hand[i]]++;
        }
        auto it=mapp.begin();
        while(it!=mapp.end()){
            auto ij=it;
            int subtract=it->second;
            // cout<<subtract<<endl;
            int t=groupSize;
            int start=it->first;
            while(ij!=mapp.end() && t--){
                if(ij!=it && ij->first - start!=1 && subtract!=0){
                    // cout<<"hi";
                    // cout<<ij->first;
                    // cout<<it->first;
                    return false;
                }
                if(ij!=it){
                    start=ij->first;
                }
                
                ij->second -= subtract;
                if(ij->second<0){
                    // cout<<"hi";
                    // cout<<it->first;
                    return false;
                }
                ij++;
            }
            if(t>0 && subtract!=0){
                // cout<<it->first;
                return false;
            }
            it++;
        }
        
        return true;

    }
};