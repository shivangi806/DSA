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
    bool search(TreeNode* root, TreeNode* subRoot){
        if(root==NULL  && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
            bool a = search(root->left,subRoot->left);
            bool b = search(root->right,subRoot->right);
            if((root->val==subRoot->val) && a && b) return true;
     return false; 
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
     if(!root) return false;
       if(search(root,subRoot)) return true;
       return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
