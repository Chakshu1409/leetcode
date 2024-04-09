class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int size=tickets.size();
        int count=0;
        for(int i=0; i<size; i++){
            if(i<=k && tickets[i] >= tickets[k]){
                count+=tickets[k];
            }
            else if(i<=k && tickets[i]<tickets[k]){
                count+=tickets[i];
            }
            else if(i>k && tickets[i] >= tickets[k]-1){
                count+=tickets[k]-1;
            }
            else{
                count+=tickets[i];
            }
        }
        return count;
    }
};