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
    string solve(TreeNode* root){
        if(root==NULL) return "ok";
        
        string lf = solve(root->left);
        string rg = solve(root->right);
        if(lf=="needcam" || rg=="needcam"){
            c++;
            return "provider";
        }else if(lf=="provider" || rg=="provider"){
            return "ok";
        }
        return "needcam";
    }
    int minCameraCover(TreeNode* root) {
        if(!root) return NULL;
        if(solve(root)=="needcam") c++;
        return c;
    }
};