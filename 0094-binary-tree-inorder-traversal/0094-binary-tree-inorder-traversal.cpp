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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        while(1){
            
            if(root==NULL){ // reached leaf node
                if(st.empty()) break;
                
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                st.push(root);
                root=root->left;
            }
        }
        return ans ;
    }
};