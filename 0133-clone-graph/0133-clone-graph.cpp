/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    map<Node* , Node*> mp;
    Node* cloneGraph(Node* root) {
        if(root==NULL) return NULL;
        Node* newbee = new Node(root->val , {}); // node val    ,     vector of neighbours
        mp[root] = newbee ;
        queue<Node*> q;
        q.push(root) ;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            for(auto it : temp->neighbors){
                if(!mp[it]){
                    mp[it]=new Node(it->val , {});
                    q.push(it);
                }
                mp[temp] ->neighbors.push_back(mp[it]);
            }
        }
        return mp[root] ;
    }
};