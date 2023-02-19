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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // level order traversal in tree karo
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int itr =0;
        if(root==NULL) return ans ;
        while(!q.empty()){
            int len = q.size();
            vector<int> ds;
            for(int i=0;i<len;i++){
                TreeNode* node = q.front();
                q.pop();
                ds.push_back(node->val);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            itr++;
            if(itr%2==0) reverse(ds.begin(),ds.end());
            ans.push_back(ds);
        }
        return ans ;
    }
};