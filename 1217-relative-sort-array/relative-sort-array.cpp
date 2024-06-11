class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int size1=arr1.size();
        int size2=arr2.size();

        vector<int> map(1001,0);

        for(int i=0; i<size1; i++){
            map[arr1[i]]++;
        }
        vector<int> ans;

        for(int i=0; i<size2; i++){
            while(map[arr2[i]] --){
                ans.push_back(arr2[i]);
            }
        }
        // return ans;
        for(int i=0; i<1001; i++){
            // int t=map[i];
            while(map[i]>0){
                ans.push_back(i);
                map[i]--;
            }
        }

        return ans;
        

    }
};