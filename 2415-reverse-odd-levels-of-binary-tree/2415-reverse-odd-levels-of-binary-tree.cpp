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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        // do bfs
        TreeNode* temp = root ;
        int c =1;
        while(!q.empty()){
            int len = q.size();
            vector<TreeNode*> nodevec;
            vector<int>  valvec;
            for(int i=0;i<len;i++){
                TreeNode* x = q.front();
                q.pop();
                valvec.push_back(x->val);
                nodevec.push_back(x);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            
            // yha mere paas each level ka value vector and node vector aa gya
            if(c%2==0){
                reverse(valvec.begin(),valvec.end());
                for(int i=0;i<nodevec.size();i++){
                TreeNode* m = nodevec[i];
                m->val = valvec[i];
            }
               }
            
            
            c++;
        }
        return root ;
    }
}; 