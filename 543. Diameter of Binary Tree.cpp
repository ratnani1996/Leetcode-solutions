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
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftSubtree = height(root->left);
        int rightSubTree = height(root->right);
        return max(leftSubtree, rightSubTree) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int sumOfHeightOfLeftSubtreeAndRightSubTree = height(root->left) + height(root->right);
        int diameterOfLeftSubTree = diameterOfBinaryTree(root->left);
        int diamaterOfRightSubTree = diameterOfBinaryTree(root->right);
        return max(sumOfHeightOfLeftSubtreeAndRightSubTree, max(diameterOfLeftSubTree, diamaterOfRightSubTree));
    }

    
};
