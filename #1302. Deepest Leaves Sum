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
    int getHeight(TreeNode * ptRoot)
    {
        if(ptRoot == nullptr)
        {
            return 0;
        }
        return 1 + max(getHeight(ptRoot->left), getHeight(ptRoot->right));
    }
    int solve(TreeNode * ptRoot, int height)
    {
        if(ptRoot == nullptr)
        {
            return 0;
        }
        if(height==1)
        {
            return ptRoot->val;
        }
        return solve(ptRoot->left, height-1) + solve(ptRoot->right, height-1);
    }
    
    int deepestLeavesSum(TreeNode * ptRoot) {
        int height = getHeight(ptRoot);
        //cout << height << endl;
        return solve(ptRoot, height);
        
    }
};
