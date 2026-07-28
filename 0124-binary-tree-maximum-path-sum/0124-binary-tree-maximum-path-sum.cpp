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
    int maxPathSum(TreeNode* root) {
        if(!root->left and !root->right){
            return root->val;
        }

        int max_sum = INT_MIN;

        max_sum = max(max_sum, root->val);

        auto dfs = [&](auto &dfs,TreeNode *node)->int{
            if(!node) return 0;

            int left_sum = max(0,dfs(dfs,node->left));

            int right_sum = max(0,dfs(dfs, node->right));

            max_sum = max(max_sum, left_sum + right_sum + node->val);


            return node->val + max(left_sum, right_sum) ;
        };


        dfs(dfs,root);

        return max_sum;


    }
};