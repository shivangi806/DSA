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
    vector<int> rightSideView(TreeNode* root) {
    
        vector<vector<int>> ans ;
        vector<int> store;
        if(root==NULL) return store;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
        vector<int> ds;
        int len = q.size();
        for(int i=0;i<len;i++){
                   TreeNode* temp = q.front();
                    q.pop(); 
                    ds.push_back(temp->val);
                    if(temp->left!=NULL) q.push(temp->left);
                    if(temp->right!=NULL) q.push(temp->right);
                    
        }
        store.push_back(ds[len-1]);
        ans.push_back(ds);
        }
        return store ;
    }
};