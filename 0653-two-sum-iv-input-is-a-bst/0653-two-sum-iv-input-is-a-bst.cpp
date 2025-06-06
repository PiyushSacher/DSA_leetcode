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
    vector<int> inorder;
    void inord(TreeNode* root){
        if(root==NULL) return;
        inord(root->left);
        inorder.push_back(root->val);
        inord(root->right);

    }
    bool findTarget(TreeNode* root, int k) {
        inord(root);
        int i=0;
        int j=inorder.size()-1;
        while(i<j){
            if(inorder[i]+inorder[j]==k) return true;
            else if(inorder[i]+inorder[j]>k) j--;
            else i++;
        }   
        return false;    
        
    }
};