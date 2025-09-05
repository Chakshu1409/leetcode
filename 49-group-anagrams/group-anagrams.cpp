class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size=strs.size();

        vector<pair<string, int>> groupedAnagrams;

        for(int i=0; i<size; i++){
            string temp=strs[i];
            sort(temp.begin(), temp.end());
            groupedAnagrams.push_back({temp, i});
        }

        sort(groupedAnagrams.begin(), groupedAnagrams.end());

        vector<vector<int>> groupedIndex;

        int i=0; 

        while(i<size){
            int j=i;
            vector<int> temp;
            while(j<size && groupedAnagrams[j].first == groupedAnagrams[i].first){
                temp.push_back(groupedAnagrams[j].second);
                j++;
            }
            groupedIndex.push_back(temp);
            i=j;
        }

        vector<vector<string>> ans;

        for(auto it: groupedIndex){
            vector<string> temp;
            for(auto ij: it){
                temp.push_back(strs[ij]);
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};