class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> v;
        v.reserve(m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(matrix[i][j]);
            }
        }
        int s=0;
        int e=v.size()-1;

        while(s<=e){
            int mid=(s+e)/2;
            if(v[mid]==target){
                return true;
            }
            else if(v[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
    }
};