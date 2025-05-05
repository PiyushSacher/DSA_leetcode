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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        
        bool leftToRight=true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>row(size);
            
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(leftToRight){
                    row[i]=curr->val;
                }
                else {
                    row[size-1-i]=curr->val;
                }

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            leftToRight=!leftToRight;
            result.push_back(row);

        }
        return result;

        
    }
};