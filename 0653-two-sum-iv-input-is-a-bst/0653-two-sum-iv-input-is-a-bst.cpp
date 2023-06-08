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
class Bstit{
  stack<TreeNode*> st;
  bool reverse=true;
  public : 
    Bstit(TreeNode* root , bool isreverse)
    {
        reverse=isreverse;
        pushNode(root);
    }
    bool hasNext()
    {
        if(st.empty()) return 0;
        return 1;
    }
    int next(){
        TreeNode* root = st.top();
        st.pop();
        if(reverse)pushNode(root->left); // reverse h mtlb left h uska
        else pushNode(root->right);
        return root->val;
    }
    
    private:
    void pushNode(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);
            if(!reverse) root=root->left;
            else root=root->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        Bstit lf(root,false); // next
        Bstit rf(root,true); // before
        int i = lf.next();
        int j=rf.next();
        while(i<j)
        {
            if(i+j==k) return 1;
            if(i+j < k)
            {
                i=lf.next();
            }
            else
            {
                j=rf.next();
            }
        }
        return 0;
    }
};