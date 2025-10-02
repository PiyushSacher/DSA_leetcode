class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //approach 
        //as longest common prefix would be same in all the elements of the vector,so we will sort them as when we will sort, all the equal elements will be group together
                // after sorting
//cluster           club
//clue              clue
//clutch            clumsy
//club              cluster
//clumsy            cluster

// now see clu is coming everywhere
//now we can just compare the first word and the last word and try to look up till where the words are common
// suppose circle is also there , then circle would be coming at the top.
        string result="";
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string start=strs[0];
        string end=strs[n-1];
        for(int i=0;i<start.length();i++){
            if(start[i]==end[i]) result+=start[i];
            else break;
        }
        return result;
    }
};