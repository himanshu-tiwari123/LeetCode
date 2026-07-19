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
    vector<vector<int>>ans;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode *>q;

        

        auto bfs =[&](auto &self, TreeNode *node)->void{
            //Base Case:
            if(!root) return;

            q.push(node);

            while(!q.empty()){
                vector<int>temp;
                int size = q.size();

                for(int i=0;i<size;i++){
                    auto node = q.front();
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
        };

        bfs(bfs,root);
        return ans;
        
    }
};