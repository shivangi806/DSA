/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // O(N) not an efficient one 
    bool findPath(vector<TreeNode*>&dpath , TreeNode* root , TreeNode* node){
        if(root==NULL) return 0;
        dpath.push_back(root);
        if(root==node) return 1;
        if(findPath(dpath,root->left,node) || findPath(dpath,root->right,node)) return 1;
        dpath.pop_back(); // inportant to  note
        return 0;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        if(!findPath(path1,root,p) || !findPath(path2,root,q)){
            return NULL;
        }
        TreeNode* ans =NULL ;
        int mini = min(path1.size(),path2.size());
        for(auto i=0;i<mini;i++){
            if(path1[i]==path2[i]) ans = path1[i];
        }
        return ans;
    }
};