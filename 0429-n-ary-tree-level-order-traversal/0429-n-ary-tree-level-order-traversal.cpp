/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        
        vector<vector<int>> ans ;
        if(root==NULL) return ans ;
        while(!q.empty()){
            int len = q.size();
            vector<int> ds;
            for(int i=0;i<len;i++){
                Node* ch = q.front();
                q.pop();
                ds.push_back(ch->val);
                for(int j=0;j<ch->children.size();j++){
                    q.push(ch->children[j]);
                }
            }
            ans.push_back(ds);
        }
        return ans ;
    }
};








