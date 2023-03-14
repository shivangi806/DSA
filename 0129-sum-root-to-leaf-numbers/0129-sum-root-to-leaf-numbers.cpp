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
    int ans = 0;
    void solve(TreeNode* root , int &ans , int sum){
        if(root->left==NULL && root->right==NULL){
            ans+=sum;
            return ;
        }
        if(root->left)  solve(root->left , ans , sum*10 + root->left->val);
        if(root->right)  solve(root->right , ans , sum*10 + root->right->val);
    }
    int sumNumbers(TreeNode* root) {
        int sum = root->val ;
        solve(root , ans , sum);
        return ans ;
    }
};