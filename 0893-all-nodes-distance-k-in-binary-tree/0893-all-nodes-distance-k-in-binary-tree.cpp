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

        queue<pair<int,int>>q1;

        unordered_set<int>visited;

        q1.push({target->val,0});

        visited.insert(target->val);

        while(!q1.empty()){
            int node = q1.front().first;
            int level = q1.front().second;
            q1.pop();

            if(level == k){

                ans.push_back(node);
                
                continue;
            }


            for(auto &it: adj[node]){

                if(visited.find(it) == visited.end()){
                    visited.insert(it);
                    q1.push({it,level+1});
                }
                
            }
        }

        return ans;

    }
};