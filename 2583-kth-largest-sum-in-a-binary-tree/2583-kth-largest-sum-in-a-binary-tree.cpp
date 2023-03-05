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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> v;
        while(!q.empty()){
            int sz = q.size();
            long long sum =0;
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            v.push_back(sum);
        }
        int level = v.size();
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        if(k>level) return -1;
        return v[k-1];
    }
};