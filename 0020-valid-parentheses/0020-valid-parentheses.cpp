class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            //if opening bracket
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            
            //else it is a closing bracket or st is empty
            else{
                //eg:   ))
                if(st.empty()) return false; 

                if(s[i]==')' && st.top()=='(') st.pop();
                else if(s[i]=='}' && st.top()=='{') st.pop();
                else if(s[i]==']' && st.top()=='[') st.pop();

                else{
                    // any unbalanced order
                    // }]
                    return false;
                }
            }
        }
        return st.empty();
        
    }
};