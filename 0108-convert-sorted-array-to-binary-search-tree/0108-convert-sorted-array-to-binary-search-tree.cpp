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
    TreeNode *createTree(int l,int h,vector<int>&nums){

        if(l>h){
            return NULL;
        }
       int mid = (l+h)/2;

       TreeNode *node = new TreeNode(nums[mid]);
  
       node->left = createTree(l,mid-1,nums);

       node->right = createTree(mid+1,h,nums);


       return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        // TreeNode *root = new TreeNode(nums[n/2]);

        return createTree(0,n-1,nums);

       

        
    }
};