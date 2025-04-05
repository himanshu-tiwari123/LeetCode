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
    map<int,int>mp;

    int maxDepth = -1;

    void findDepth(TreeNode *node,int depth){
        if(node==NULL){
            return;
        }
        mp[node->val] = depth;

        maxDepth = max(maxDepth,depth);

        findDepth(node->left,depth+1);

        findDepth(node->right,depth+1);

    }
    TreeNode* findLCA(TreeNode *node){
        if(!node){
            return NULL;
        }

        if(mp[node->val] == maxDepth){
            return node;
        }

        TreeNode *leftNode = findLCA(node->left);
        TreeNode *rightNode = findLCA(node->right);

        if(leftNode!=NULL and rightNode!=NULL){
            return node;
        }

        return leftNode!=NULL ? leftNode:rightNode;


    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = 0;
        // mp[root->val] = 0;
        findDepth(root,depth);

        //Now after finding the depth,we need to find the nodes at those depth:
        TreeNode *ans = findLCA(root);

        return ans;
    }
};