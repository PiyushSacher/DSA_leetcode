class Solution {
public:
    int fun(int num,int steps){
        if(num==0) return steps;
        if(num%2==0) return fun(num/2,steps+1);
        else return fun(num-1,steps+1);
    }
    int numberOfSteps(int num) {
        return fun(num,0);
        
    }
};