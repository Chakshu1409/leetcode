class MinStack {
private:

    vector<pair<int,int> > st;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minValue=getMin();
        if(st.empty() || minValue>val){
            minValue=val;
        }
        st.push_back({minValue,val});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        if(!st.empty()){
            return st.back().second;
        }
        return -1;
    }
    
    int getMin() {
        if(!st.empty()){
            return st.back().first;
        }
        return -1;
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