class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int size=students.size();
        int zero=0;
        int one=0;
        for(int i=0; i<size; i++){
            if(students[i]==1){
                one++;
            }
            else{
                zero++;
            }
        }
        for(int i=0; i<size; i++){
            if(sandwiches[i]==1){
                if(one>0){
                    one--;
                }
                else{
                    return size-i;
                }
            }
            else{
                if(zero>0){
                    zero--;
                }
                else{
                    return size-i;
                }
            }
        }
        return 0; 
    }
};