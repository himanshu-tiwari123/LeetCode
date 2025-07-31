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
#define ll long long
class Solution {
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll max_width = 0;

        bfs(root,max_width);

        return max_width;
    }

private:
    void bfs(TreeNode *root, ll &max_width){
       queue<pair<TreeNode *,ll>>q;
       q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            ll left = 0,right = 0;

            ll offset = q.front().second;

            for(int i=0;i<size;i++){
                auto [node,level] = q.front();
                q.pop();
                level -= offset;
                if(i==0 ){
                    left = level;
                }
                if(i==size-1){
                    right = level;
                }
                if(node->left){
                    q.push({node->left,((ll)2*level)+1});
                }

                if(node->right){
                    q.push({node->right,((ll)2*level)+2});
                }
            }
            
            max_width = max(max_width,(right-left+1));            
        }
    }
};