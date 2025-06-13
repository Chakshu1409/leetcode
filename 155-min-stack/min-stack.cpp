class MinStack {
public:
    stack<vector<int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            if(st.top()[1] > val){
                st.push({val,val});
            }
            else{
                st.push({val,st.top()[1]});
            }
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top()[0];
    }
    
    int getMin() {
        return st.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */