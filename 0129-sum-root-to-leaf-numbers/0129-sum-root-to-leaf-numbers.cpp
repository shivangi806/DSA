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
    int ans ;
    void solve(TreeNode* root , int each_sum){
        if(root==NULL) return ;
        each_sum = each_sum*10 + root->val ;
        if(root->left==NULL && root->right==NULL){
            ans += each_sum;
            return ;
        }
        solve(root->left , each_sum);
        solve(root->right, each_sum);
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        solve(root,0); 
        return ans ;
    }
};