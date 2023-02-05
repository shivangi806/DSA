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
    
    int solve(TreeNode* root , int &sum){
        if(root==NULL) return 0;
        int l = solve(root->left , sum);
        int r = solve(root->right , sum);
        
        sum = max(sum , l+r+root->val);
        return max(max(l,r)+root->val , 0) ;
    }
    int maxPathSum(TreeNode* root) {
        int sum =INT_MIN;
        solve(root,sum);
        return sum ;
    }
};