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
    void findAns(TreeNode *node,int val){

        if(val < node->val){
           if(node->left){
            findAns(node->left,val);
           }else{
             node->left =  new TreeNode(val);
           }
        }


        if(val > node->val){
            if(node->right){
                findAns(node->right,val);
            }else{
                node->right = new TreeNode(val);
            }
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode *ans = new TreeNode(val);

            return ans;
        }

        TreeNode *head = root;

        findAns(root,val);

        return head;
    }
};