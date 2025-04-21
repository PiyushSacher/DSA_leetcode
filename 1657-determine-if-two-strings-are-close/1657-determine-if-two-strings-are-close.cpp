class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        if(word1.size()!=word2.size()) return false;

        for(int i=0;i<word1.size();i++){
            char ch1=word1[i];
            char ch2=word2[i];

            int idx1=ch1-'a';
            int idx2=ch2-'a';

            freq1[idx1]++;
            freq2[idx2]++;
        }

        for(int i=0;i<freq1.size();i++){
            if(freq1[i]==0 && freq2[i]==0) continue;
            if(freq1[i]!=0 && freq2[i]!=0) continue;
            return false;
        }

        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());

        return (freq1==freq2);        
    }
};