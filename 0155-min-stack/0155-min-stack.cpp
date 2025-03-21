class MinStack {
public:
    stack<long long >st;
    long long mini;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(long long val) {
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else{
            if(val>mini) st.push(val);
            else{
                st.push(2*val-mini);
                mini=val;
            }
        }     
    }
    
    void pop() {
        if(st.top()<mini){ //updated val inserted in stack
            mini=2*mini-st.top(); //so that we can go back to prevMini
        }   
        st.pop();     
    }
    
    int top() {
        if(st.top()<mini) return mini; //updated
        else return st.top();
        
    }
    
    int getMin() {
        return mini;
        
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