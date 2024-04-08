class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int size=students.size();
        queue<int> student;
        queue<int> sandwich;

        for(int i=0; i<size; i++){
            student.push(students[i]);
            sandwich.push(sandwiches[i]);
        }
        int count=0;
        while(!student.empty()){
            if(student.front()==sandwich.front()){
                student.pop();
                sandwich.pop();
                count=0;
            }
            else{
                int top=student.front();
                student.pop();
                student.push(top);
                count++;
            }
            if(count>student.size() + 1){
                return student.size();
            }
        }
        return 0;
    }
};