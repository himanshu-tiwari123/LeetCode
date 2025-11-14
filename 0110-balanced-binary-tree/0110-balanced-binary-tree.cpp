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
    int depth(TreeNode* root) {
    if (!root) return 0;
    
    int leftDepth = depth(root->left);
    if (leftDepth == -1) return -1;  // Early termination!
    
    int rightDepth = depth(root->right);
    if (rightDepth == -1) return -1;  // Early termination!
    
    if (abs(leftDepth - rightDepth) > 1) {
        return -1;  // Signal imbalance immediately
    }
    
    return 1 + max(leftDepth, rightDepth);
}
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;

    }
};