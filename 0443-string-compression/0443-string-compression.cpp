class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0;
        for(int i=0;i<n;){
            char curr_char=chars[i];
            int count=0;
            while(i<n && chars[i]==curr_char){
                count++;
                i++;
            }
            //assigning
            chars[index]=curr_char;
            index++;
            

            
            if(count>1){
                string str=to_string(count);
                for(char ch:str){
                    chars[index]=ch;
                    index++;
                }
            }
        }
        return index;
    }
};