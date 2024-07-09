class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double size=customers.size();

        double total=0;
        int currentTime=0;

        for(int i=0; i<size; i++){
            int startTime=customers[i][0];
            int timeTaken=customers[i][1];

            if(currentTime >= startTime){
                total+= currentTime-startTime;
                total+= timeTaken;
                
                currentTime+=timeTaken;
            }
            else{
                currentTime= startTime+timeTaken;
                total+=timeTaken;
            }
        }

        return total/size;

    }
};