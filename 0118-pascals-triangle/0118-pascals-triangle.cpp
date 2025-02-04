class Solution {
public:
    vector<int> generateRow(int row){
        int ans=1;
        vector<int> temp;
        temp.push_back(1);
        for(int col=1;col<row;col++){
            ans=ans*(row-col);
            ans=ans/col;
            temp.push_back(ans);
        }
        return temp;
    }

    vector<vector<int>> generate(int N) {
        vector<vector<int>> ans;
        for(int i=1;i<=N;i++){
            ans.push_back(generateRow(i)) ;           
        }
        return ans;
        
    }
};