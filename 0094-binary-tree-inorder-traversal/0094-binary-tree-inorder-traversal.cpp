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
    vector<int>v;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return v;
        inorderTraversal(root->left);
        v.push_back(root->val);
        inorderTraversal(root->right);

        return v;     
    }


 
//  //iterative
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>v;
//         stack<TreeNode*>st;
//         TreeNode* curr=root;
//         while(!st.empty() || curr != NULL){
//             if(curr!=NULL){
//                 st.push(curr);
//                 curr=curr->left;
//             }
//             else{
//                 v.push_back((st.top())->val);
//                 curr=st.top();
//                 st.pop();
//                 curr=curr->right;

//             }    
//         }
//         return v;
//     }
};