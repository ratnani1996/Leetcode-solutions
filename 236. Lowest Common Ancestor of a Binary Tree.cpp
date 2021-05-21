/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findNodes(TreeNode *root, TreeNode *q){
        if(root == NULL){
            return false;
        }
        if(root->val == q->val){
            return true;
        }
        return findNodes(root->left, q) || findNodes(root->right, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        if(findNodes(root->left, p) && findNodes(root->left, q)){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(findNodes(root->right, p) && findNodes(root->right, q)){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
