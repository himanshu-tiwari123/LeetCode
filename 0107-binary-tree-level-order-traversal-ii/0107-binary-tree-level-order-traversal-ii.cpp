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
    void bfs(TreeNode *node,vector<vector<int>>&ans){
        queue<TreeNode*>q;
        q.push(node);

        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(temp);
        }
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>ans;

        if(root == NULL){
            return ans;
        }
        
        bfs(root,ans);

        reverse(ans.begin(),ans.end());

        return ans;
    }
};