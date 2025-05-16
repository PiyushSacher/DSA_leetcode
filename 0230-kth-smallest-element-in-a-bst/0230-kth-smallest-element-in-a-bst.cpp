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
    int count=0;
    int ans=-1;
    void smallest(TreeNode* root,int k){
        if(root==NULL) return;
        smallest(root->left,k);
        count++;
        if(count==k) ans=root->val;
        smallest(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        smallest(root,k);  
        return ans;      
    }
};