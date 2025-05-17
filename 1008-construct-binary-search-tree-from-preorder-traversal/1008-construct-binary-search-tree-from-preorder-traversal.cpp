/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

 */

    
class Solution {
public:
    int idx=0;
    TreeNode* solve(vector<int>preorder,vector<int>inorder,int start,int end){
        if(start>end) return NULL;
        TreeNode* newNode=new TreeNode(preorder[idx]);
        int i=start;
        for(;i<inorder.size()-1;i++){
            if(inorder[i]==preorder[idx]) break;
        }

        idx++;        
        
        newNode->left=solve(preorder,inorder,start,i-1);
        newNode->right=solve(preorder,inorder,i+1,end);
        return newNode;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        vector<int>inorder(n);
        for(int i=0;i<n;i++){
            inorder[i]=preorder[i];
        }
        sort(inorder.begin(),inorder.end());
        int idx=0;
        return solve(preorder,inorder,0,n-1);  
    }
};