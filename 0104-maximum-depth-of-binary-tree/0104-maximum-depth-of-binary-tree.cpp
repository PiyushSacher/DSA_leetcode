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
  //iterative
    int maxDepth(TreeNode* root) {
        int depth=0;
        if(root==NULL) return depth;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            depth++;
            while(size){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                size--;
            }
        }
        return depth;
    }








    // int maxDepth(TreeNode* root) {
    //     if(root==NULL) return 0;
    //     int leftDepth=maxDepth(root->left);
    //     int rightDepth=maxDepth(root->right);

    //     return 1+max(leftDepth,rightDepth);   
    // }




};