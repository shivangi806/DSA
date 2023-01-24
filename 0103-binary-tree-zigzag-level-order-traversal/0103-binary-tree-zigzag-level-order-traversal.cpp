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
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        if(root==nullptr){
            return res;
        }
        int c=0;
        while(!q.empty()){
            vector<int> level;
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            if(c%2!=0) {
                reverse(level.begin(),level.end());
            }
            res.push_back(level);c++;
        }
      return res;
    }
};