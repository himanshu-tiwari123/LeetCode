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
    pair<int,TreeNode*>findAns(TreeNode *node){
        if(!node){
            return {0,NULL};
        }

        pair<int,TreeNode*>leftNode = findAns(node->left);
        pair<int,TreeNode*>rightNode = findAns(node->right);

        if(leftNode.first == rightNode.first){
            //Both the depths are same=>both are the deepese leaves:
            //So the currNode is their LCA:
            return {leftNode.first+1,node};
        }
        else if(leftNode.first > rightNode.first){
            //It means left subtree has deepest leaf nodes, So:
            return {leftNode.first+1,leftNode.second}; 
        }else{
            return {rightNode.first+1,rightNode.second};
        }
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
       return findAns(root).second;
    }
};