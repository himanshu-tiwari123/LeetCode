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
    vector<string>ans;
    void dfs(TreeNode *node, string s){

        //Base Case:
        // if(!node){
        //     return ;
        // }

        if(node->left == NULL and node->right==NULL){
            //we are at leaf node:
            ans.push_back(s);
            return;
        }
        
        
        
        if(node->left){
            
            dfs(node->left,s+"->"+to_string(node->left->val));
            
        }
        

        if(node->right){
            
            dfs(node->right,s+"->"+to_string(node->right->val));
            
        }
        
        
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        s += to_string(root->val);
        dfs(root,s);
        return ans;
    }
};