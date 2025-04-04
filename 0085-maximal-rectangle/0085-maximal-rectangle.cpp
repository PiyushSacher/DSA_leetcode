class Solution {
public:
    vector<int> findNSE(vector<int> &arr) {
        int n=arr.size();
        vector<int>nse(n);
        stack<int>st;
        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int> &arr) {
        int n=arr.size();
        vector<int>pse(n);
        stack<int>st;
        for (int i=0;i<n;i++) {
            while (!st.empty( )&& arr[st.top()]>arr[i]) st.pop();
            pse[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse=findNSE(heights);
        vector<int>pse=findPSE(heights);

        int maxi=0;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }

        return maxi;               
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>pSum(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(matrix[j][i]=='0') sum=0;
                else sum+=1;
                pSum[j][i]=sum;

            }
        }   

        int maxArea=-1;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,largestRectangleArea(pSum[i]));
        }    

        return maxArea; 
    }
};