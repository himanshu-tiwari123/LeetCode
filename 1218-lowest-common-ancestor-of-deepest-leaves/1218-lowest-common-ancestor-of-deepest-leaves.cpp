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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
    
private:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }
        if (right.first > left.first) {
            return {right.first + 1, right.second};
        }
        // If depths are equal, current node is LCA
        return {left.first + 1, node};
    }
};