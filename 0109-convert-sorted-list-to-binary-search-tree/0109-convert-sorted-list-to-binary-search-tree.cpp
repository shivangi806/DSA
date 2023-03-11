/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode{
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
    
    TreeNode* convertBst(vector<int>&list,int st , int end){
        TreeNode* temp;
        if(st>end) return NULL ;
        int mid = (st+end)/2 ;
        temp = new TreeNode(list[mid]);
        temp->left = convertBst(list,st,mid-1);
        temp->right = convertBst(list,mid+1,end);
        return temp ;
        
    }
    void takelist(ListNode* head , vector<int>&list){
        ListNode* temp = head;
        while(temp!=NULL){
            list.push_back(temp->val);
            temp=temp->next;
        }
    }
    TreeNode* sortedListToBST(ListNode* head) {
       // put all vals of linekd list ina vector and then
        // with the help of all vals create a bst
        vector<int> list;
        takelist(head,list);
        // list aa gya    -10 , -3 , 0 , 5 ,9
        sort(list.begin(),list.end());
        int n = list.size();
        return convertBst(list,0,n-1);
    }
};







