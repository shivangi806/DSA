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
    
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int in_st ,int  in_end , int ps_st , int ps_end,map<int,int>& mp){
        if(in_st > in_end || ps_st > ps_end) return NULL;
        TreeNode* root = new TreeNode(postorder[ps_end]);
        int indexofroot = mp[root->val];
        int numbersinleft = indexofroot - in_st ;
        int numbersinright = in_end - indexofroot;
        root->left = solve(inorder,postorder,in_st , indexofroot-1 ,ps_st , ps_st+numbersinleft-1 , mp);
        root->right = solve(inorder,postorder,indexofroot+1 , in_end ,ps_st + numbersinleft,ps_end -1 ,mp);
        return root ;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // root kisme milega post order se last index hoga
        // to ease the finding of root take a map
        // hmara preorder / postorder me hi root milega to hme inorder ka start or end ko modify karna hoga accordingly
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        return solve(inorder,postorder,0,inorder.size()-1 ,0,postorder.size()-1,mp);
    }
};