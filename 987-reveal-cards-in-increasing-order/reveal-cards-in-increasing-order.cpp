class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int size=deck.size();
        sort(deck.begin(),deck.end());
        queue<int> q;
        for(int i=0; i<size; i++){
            q.push(i);
        }
        vector<int> ans(size,0);
        int i=0;
        while(!q.empty()){
            ans[q.front()]=deck[i];
            q.pop();
            if(!q.empty()){
                int temp=q.front();
                q.pop();
                q.push(temp);
            }
            i++;
        }
        return ans;
    }
};