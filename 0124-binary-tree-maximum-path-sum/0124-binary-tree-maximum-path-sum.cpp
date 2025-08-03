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
    int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        return dfs(root);

    }

    private:
    int dfs(TreeNode * root){
        //Base Case:
        if(root==NULL){
            return 0;
        }
        
        int leftSum =max(0, root->val +  maxPathSum(root->left));

        int rightSum =max(0,root->val + maxPathSum(root->right));

        max_sum = max(max_sum, leftSum+rightSum);

        return leftSum + rightSum - root->val ;
    }
};