class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size=asteroids.size();
        stack<int> st;
        vector<int> ans;
        for(int i=0; i<size; i++){
            if(asteroids[i] < 0){
                bool flag=false;
                while(!st.empty() && abs(asteroids[i]) >= st.top()){
                    if(abs(asteroids[i]) == st.top()){
                        flag=true;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if(st.empty() && !flag){
                    ans.push_back(asteroids[i]);
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        int sizeTemp=temp.size();

        for(int i=sizeTemp-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};