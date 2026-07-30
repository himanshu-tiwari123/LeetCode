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
    int longestUnivaluePath(TreeNode* root) {
        int  maxLength = 0;

        auto dfs = [&](auto &dfs,TreeNode *node)->int{

            if(!node) return 0;

            int left = dfs(dfs,node->left);

            int right = dfs(dfs, node->right);

            int leftLength = 0, rightLength = 0;

            if(node->left and node->left->val == node->val) leftLength = left+1;
            if(node->right and node->right->val == node->val) rightLength = right+1;

            maxLength = max(maxLength, leftLength + rightLength);


            return max(leftLength, rightLength);
        };

    
        dfs(dfs,root);

        return maxLength;
    }
};