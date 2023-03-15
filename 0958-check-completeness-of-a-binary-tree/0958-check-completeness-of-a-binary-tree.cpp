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
    bool dfs(int idx , TreeNode* root , int cnt){
        if(root==NULL) return 1;
        if(idx > cnt) return 0;
        return dfs(2*idx , root->left , cnt) && dfs(2*idx+1 , root->right , cnt) ;
    }
    int countNode(TreeNode* root){
        if(root==NULL) return 0;
        return countNode(root->left) + countNode(root->right) + 1;
    }
    bool isCompleteTree(TreeNode* root) {
        // using dfs by storing the nodes value in an array
        // to find the total number of nodes first
        int totalNodes = countNode(root) ;
        // now we will write the dfs for collecting the nodes in an array 
        // with starting index 1 ..so left child will be at index 2*i and right child will be at index 2*i+1
        return dfs(1,root,totalNodes);
    }
};