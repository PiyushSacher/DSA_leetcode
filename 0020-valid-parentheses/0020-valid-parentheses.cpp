class Solution {
public:
    bool isValid(string s) {
            stack<char> st;
    for(int i=0;i<s.size();i++){
        //opening bracket , therefore push in the stack
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            st.push(s[i]);
        }
        else{
            //closing bracket, therefore check if the closing bracket == stacks top counter opening bracket and also check if stack is not empty 
            if(s[i]==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
            else if(s[i]==']' && !st.empty() && st.top()=='['){
                st.pop();
            }
            else if(s[i]=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
            //stack will be empty or we are getting bracket of these type (( } whose closing bracket is not matching stacks top counter opening bracket
                
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        
        return false;
    }


        
    }
};