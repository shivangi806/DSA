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
    
    string solve(TreeNode* root, vector<TreeNode*> & ans ,  unordered_map<string , int> &mp){
        if(root==NULL) return "";
        string s ;
        s =to_string(root->val) + ","+solve(root->left , ans , mp) + ","+solve(root->right , ans , mp); // s me 4 aa gya pehle
        mp[s]++;
        if(mp[s]==2) ans.push_back(root);
        return s;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string , int> mp;
        solve(root , ans , mp);
        return ans ;
    }
};