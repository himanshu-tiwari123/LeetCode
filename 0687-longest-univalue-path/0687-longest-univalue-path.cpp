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

        auto dfs = [&](auto &dfs,TreeNode *node, int parent)->int{

            if(!node) return 0;

            int leftLength = dfs(dfs,node->left,node->val);

            int rightLength = dfs(dfs, node->right,node->val);

            maxLength = max(maxLength, leftLength + rightLength);


            return node->val == parent ?  1+ max(leftLength,rightLength) : 0;
        };

    
        dfs(dfs,root,-1);

        return maxLength;
    }
};