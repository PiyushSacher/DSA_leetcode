class Solution {
public:
    
    string countAndSay(int n) {
        if(n==1) return "1";
        string str=countAndSay(n-1);
        string res="";        

        for(int i=0;i<str.size(); ){
            int count=0;
            char curr=str[i];

            while(i<str.size() && str[i]==curr){
                count++;
                i++;
            }

            res+=to_string(count);
            res+=curr;
        }
        return res;
    }
};