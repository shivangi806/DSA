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
    bool help(TreeNode* p , TreeNode* q){
        if(p==NULL && q==NULL) return 1;
        if(p==NULL || q==NULL) return 0;
       // if(root->left==root->right) return 1;
        if(p->val!=q->val) return 0;
        return p->val==q->val && help(p->left,q->right) && help(p->right,q->left);

    }
    bool isSymmetric(TreeNode* root) {
         if(root==NULL) return 1;
        return help(root->left , root->right) ;
    }
};