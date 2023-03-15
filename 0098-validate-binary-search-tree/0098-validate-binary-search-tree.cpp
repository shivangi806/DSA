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
public:
    
    // by setting range for each node and checking either it is in that range or not 
    bool solve(TreeNode* root , long min , long max){
        if(root==NULL) return 1;
        if(root->val > min && root->val < max && solve(root->left , min , root->val) && solve(root->right , root->val ,max)) return 1;
        return 0;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};