/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>>adj;

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();

            if(node->left){
                adj[node->val].push_back(node->left->val);
                adj[node->left->val].push_back(node->val);
                q.push(node->left);
            }

            if(node->right){
                adj[node->val].push_back(node->right->val);
                adj[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }

        

        vector<int>ans;

        queue<pair<TreeNode *,int>>q1;

        unordered_set<int>visited;

        q1.push({target,0});

        while(!q1.empty()){
            TreeNode *node = q1.front().first;
            int level = q1.front().second;
            q1.pop();

            visited.insert(node->val);

            if(level == k){
                if(node->val == target->val ){
                    if(k == 0){
                        ans.push_back(node->val);
                    }
                }else{
                    ans.push_back(node->val);
                }
            }


            for(auto &it: adj[node->val]){

                if(visited.find(it) == visited.end()){
                    visited.insert(it);

                    TreeNode *newNode = new TreeNode(it);
                    q1.push({newNode,level+1});
                }
                
            }
        }

        return ans;

    }
};