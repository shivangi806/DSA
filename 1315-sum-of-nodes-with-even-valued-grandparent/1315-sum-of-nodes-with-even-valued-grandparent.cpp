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
    int sum=0;
    void solve(TreeNode* root){
        if(root==NULL) return ;
        if(root->val % 2==0){ 
            child(root->left);
            child(root->right);
        }
       solve(root->left);
       solve(root->right);
    }
    
    void child(TreeNode* root){
        if(root==NULL) return;
        if(root->left)sum+=root->left->val;
        if(root->right)sum+=root->right->val;
    }
    int sumEvenGrandparent(TreeNode* root) {
        solve(root);
        return sum ;
    }
};