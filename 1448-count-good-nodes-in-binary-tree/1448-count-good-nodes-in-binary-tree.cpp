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
    int c=0;
    void solve(int maxi , TreeNode* root){
        if(root==NULL) return ;
        if(root->val>=maxi){
            c++;
            maxi=root->val;
        }
        solve(maxi,root->left);
        solve(maxi,root->right);
    }
    int goodNodes(TreeNode* root) {
        int maxi = INT_MIN;
        solve(maxi,root);
        return c;
    }
};