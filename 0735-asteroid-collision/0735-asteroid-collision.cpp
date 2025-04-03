class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0) st.push(asteroids[i]);
            else{
                while(!st.empty() && abs(asteroids[i])>st.top() && st.top()>0) st.pop();
                if(st.empty() || st.top()<0) st.push(asteroids[i]);
                else if(!st.empty() && abs(asteroids[i])==st.top()) st.pop();
            }
            
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};