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
    int c=0;
    string wantsCamera(TreeNode* root){
        if(root==NULL) return "inWatch";
        
        string lefty = wantsCamera(root->left);
        string righty = wantsCamera(root->right);
        if(lefty=="wantCam" || righty == "wantCam"){
            c++;
            return "provideCam";
        }
        else if(lefty=="provideCam" || righty=="provideCam"){
            return "inWatch";
        }
        return "wantCam" ;
    }
    int minCameraCover(TreeNode* root) {
        if(wantsCamera(root)=="wantCam"){
            c++;
        }
        return c;
    }
};