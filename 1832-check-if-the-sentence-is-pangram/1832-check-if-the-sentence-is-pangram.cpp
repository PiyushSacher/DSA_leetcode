class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> temp(26,0);
        for(int i=0;i<sentence.size();i++){
            int curr=sentence[i]-'a';
            temp[curr]++;
        }

        for(int i=0;i<temp.size();i++){
            if(temp[i]==0) return false;
        }
        return true;
    }
};