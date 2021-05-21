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
    vector<int> rightSideView(TreeNode* root) {
        {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int queueSize = q.size();
            for (int i = 0; i < queueSize; i++)
            {
                if (i == queueSize - 1)
                {
                    result.push_back(q.front()->val);
                }

                if (q.front()->left != NULL)
                {
                    q.push(q.front()->left);
                }
                if (q.front()->right != NULL)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return result;
    }
    }
};
